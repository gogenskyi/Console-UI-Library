#include "Console.h"
#include <memory>

#include "Widget/Button.h"
#include "Widget/Borders/Bottom.h"
#include "Widget/Borders/Header.h"

void Console::CreateApplication(const std::string &page_name,std::vector<std::unique_ptr<widget>> &widgets)
{
    page_title = page_name;
    frame.push_back(std::make_unique<Header>(page_name,50));
    frame.push_back(std::make_unique<Border>());
    frame.push_back(std::make_unique<Bottom>('_'));
    for (auto &el : widgets) {
        context.push_back(std::move(el));
    }
    UpdateState();
}

void Console::UpdateState() {
    std::system("clear");
    std::cout<<frame[Border::FRAME::HEADER]->GetLine()<<std::endl;
    for (auto &widget : context) {
        if (dynamic_cast<Widget::Button*>(widget.get())) {
            buttons.push_back(std::move(widget));
            continue;
        }
        std::cout<<frame[Border::FRAME::BORDER]->GetLine()<<'\t'<<widget->Text<<"\t"<<std::endl;
    }
    std::cout<<frame[Border::FRAME::BOTTOM]->GetLine()<<std::endl;
    for (const auto &el : buttons) {
        if (auto* button = dynamic_cast<Widget::Button*>(el.get())) {
            std::cout<<frame[Border::FRAME::BORDER]->GetLine()<<"  "<<button->GetCommand()<<":  "<<button->Text<<'\t';
        }
    }
    std::cout<<std::endl<<frame[Border::FRAME::BOTTOM]->GetLine()<<std::endl;
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

std::string Console::Input() {
    std::string input_data;
    std::cin>>input_data;
    return input_data;
}
