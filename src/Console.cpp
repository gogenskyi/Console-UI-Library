#include "Console.h"
#include <memory>

#include "Widget/Borders/Bottom.h"
#include "Widget/Borders/Header.h"

void Console::CreateApplication(const std::vector<std::unique_ptr<widget>> &widgets)
{
    frame.push_back(std::make_unique<Header>("Title",30));
    frame.push_back(std::make_unique<Border>());
    frame.push_back(std::make_unique<Bottom>('2'));
    for (auto &el : widgets) {
        context.push_back(std::make_unique<widget>(*el));
    }

    UpdateState();
}

void Console::UpdateState() {
    std::system("clear");
    std::cout<<frame[Border::FRAME::HEADER]->GetLine()<<std::endl;
    for (const auto &widget : context) {
        std::cout<<frame[Border::FRAME::BORDER]->GetLine()<<'\t'<<widget->Command<<std::endl;
    }
    std::cout<<frame[Border::FRAME::BOTTOM]->GetLine()<<std::endl;
}
