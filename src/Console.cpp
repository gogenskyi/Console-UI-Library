#include "Console.h"
#include <memory>

#include "Widget/Button.h"
#include "Widget/Borders/Bottom.h"
#include "Widget/Borders/Frame.h"
#include "Widget/Borders/Header.h"
#include "Widget/Borders/Frames.h"

void Console::CreateApplication(const std::string &page_name,std::vector<std::unique_ptr<widget>> &widgets)
{
    page_title = page_name;
    frame.push_back(std::make_unique<Header>(page_name,50));
    frame.push_back(std::make_unique<Border>("|"));
    frame.push_back(std::make_unique<Bottom>('_'));
    for (auto &el : widgets) {
        context.push_back(std::move(el));
    }
    UpdateState();
}

void Console::UpdateState() {
    std::system("clear");
    std::cout<<(GetFrame(HEADER)->GetLine())<<std::endl;
    for (auto &widget : context) {
        if (dynamic_cast<Widget::Button*>(widget.get())) {
            buttons.push_back(std::move(widget));
            continue;
        }
        if (dynamic_cast<Widget::TextMessage*>(widget.get())) { // always false condition
            text_messages.push_back(std::move(widget));
            continue;
        }
    }
    for (const auto& message : text_messages) {
        if (const auto el = dynamic_cast<Widget::TextMessage*>(message.get())) {
            el->PrintTextMessage();
        }
    }
    auto bottom = GetFrame(BOTTOM)->GetLine();  // needs refactor
    std::cout<<bottom<<std::endl;
    PrintButtons();
    std::cout<<std::endl<<bottom<<std::endl;
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
