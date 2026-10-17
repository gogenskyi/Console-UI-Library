#include "Console.h"
#include <memory>

void Console::CreateApplication(const std::vector<std::unique_ptr<widget>> &widgets) {
    for (auto &el : widgets) {
        context.push_back(std::make_unique<widget>(*el));
    }
    UpdateState();
}

void Console::UpdateState() {
    std::system("clear");
    for (const auto &widget : context) {
        std::cout<<widget->Command<<std::endl;
    }
}
