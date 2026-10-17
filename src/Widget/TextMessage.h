//
// Created by Mykola on 16.10.2026.
//
#ifndef TEXTMESSAGE_H
#define TEXTMESSAGE_H


#include <string>
#include "Widget.h"
#include "Colors/Colors.h"

namespace Widget {
    class TextMessage : public widget {
    public:
        explicit TextMessage(const std::string &message);
        explicit TextMessage(const std::string &message,Color::COLOR);

    private:
        std::string text;
    };
}

#endif // TEXTMESSAGE_H
