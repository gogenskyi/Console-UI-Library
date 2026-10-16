#include "Console.h"

void Console::CreateApplication(const std::vector<widget> &widgets) {
    context = widgets;
    UpdateState();
}

void Console::UpdateState() {
    std::system("clear");
    for (auto &widget : context) {
        system(widget.Command.c_str());
    }
}
