//
// Created by Mykola on 17.10.2026.
//

#include <functional>
#include <utility>
#include "Button.h"

std::unique_ptr<std::function<void()>> Widget::Button::GetFuncPtr() {
    return std::move(func_ptr);
}

Widget::Button::Button(const std::function<void()>& func, std::string text,const std::string &Command) {
    this->Command = Command;
    func_ptr = std::make_unique<std::function<void()>>(func);
    Text = std::move(text);
}
