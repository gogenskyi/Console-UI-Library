//
// Created by Mykola on 16.10.2026.
//

#include "TextMessage.h"

Widget::TextMessage::TextMessage(std::string message) {
    message = console_message + message;
    this->Command = message;

}