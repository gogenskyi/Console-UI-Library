//
// Created by Mykola on 16.10.2026.
//

#include "TextMessage.h"

Widget::TextMessage::TextMessage(const std::string &message) {
    text = message;
}

Widget::TextMessage::TextMessage(const std::string &message, const Color::COLOR color){
    text = message + Color::GetColor(color) + message + "\033[0m";
}

