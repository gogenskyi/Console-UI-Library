#include "Console.h"
#include <memory>

#include "Widget/Button.h"
#include "Widget/Borders/Bottom.h"
#include "Widget/Borders/Frame.h"
#include "Widget/Borders/Header.h"

void Console::CreateApplication(const std::string &page_name,std::vector<std::unique_ptr<widget>> &widgets)
{
    page_title = page_name;
    Frame::frame.push_back(std::make_unique<Header>(page_name,50));
    Frame::frame.push_back(std::make_unique<Border>());
    Frame::frame.push_back(std::make_unique<Bottom>('_'));
    for (auto &el : widgets) {
        context.push_back(std::move(el));
    }
    UpdateState();
}

void Console::UpdateState() {
    std::system("clear");
    std::cout<<Frame::GetFrame(Frame::HEADER)->GetLine()<<std::endl;
    for (auto &widget : context) {
        if (dynamic_cast<Widget::Button*>(widget.get())) {
            buttons.push_back(std::move(widget));
            continue;
        }
        if (dynamic_cast<Widget::TextMessage*>(widget.get())) {
            text_messages.push_back(std::move(widget));
            continue;
        }
    }
    for (const auto& message : text_messages) {
        if (const auto el = dynamic_cast<Widget::TextMessage*>(message.get())) {
            el->PrintTextMessage();
        }
    }
    std::cout<< Frame::GetFrame(Frame::BOTTOM)->GetLine()<<std::endl;
    PrintButtons();
    std::cout<<std::endl<< Frame::GetFrame(Frame::BOTTOM)->GetLine()<<std::endl;
    ExeсuteFunc(Input());
}

void Console::ExeсuteFunc(const std::string &input_data) {
    for (const auto &el : buttons) {
        if (auto* button = dynamic_cast<Widget::Button*>(el.get())) {
            if (button->GetCommand() == input_data) {
                auto func =button->GetFuncPtr();
                (*func)();
            }
        }
    }
}

void Console::PrintButtons() {
    for (const auto &el : buttons) {
        if (const auto* button = dynamic_cast<Widget::Button*>(el.get())) {
            button->PrintButton();
        }
    }
}

std::string Console::Input() {
    std::string input_data;
    std::cin>>input_data;
    return input_data;
}
