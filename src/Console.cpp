#include "Console.h"
#include <memory>

#include "Widget/Button.h"
#include "Widget/Borders/Bottom.h"
#include "Widget/Borders/Header.h"

void Console::CreateApplication(const std::string &page_name,const std::vector<std::unique_ptr<widget>> &widgets)
{
    page_title = page_name;
    frame.push_back(std::make_unique<Header>(page_name,30));
    frame.push_back(std::make_unique<Border>());
    frame.push_back(std::make_unique<Bottom>('2'));
    for (auto &el : widgets) {
        context.push_back(std::make_unique<widget>(*el));
    }
    UpdateState();
}

void Console::UpdateState() {
    std::system("clear");
    std::vector<std::unique_ptr<widget>> Buttons;
    std::cout<<frame[Border::FRAME::HEADER]->GetLine()<<std::endl;
    for (auto &widget : context) {
        std::cout<<frame[Border::FRAME::BORDER]->GetLine()<<'\t'<<widget->Text<<"\t"<<std::endl;
        if (dynamic_cast<Widget::Button*>(widget.get())) {
            Buttons.push_back(std::move(widget));
        }
    }
    for (const auto &el : Buttons) {
        std::cout<<el->Text<<'\t';
    }
    std::cout<<frame[Border::FRAME::BOTTOM]->GetLine()<<std::endl;
    std::cin.get();
}
