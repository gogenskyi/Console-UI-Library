//
// Created by Mykola on 16.10.2026.
//
#ifndef TEXTMESSAGE_H
#define TEXTMESSAGE_H


#include <iostream>
#include <string>
#include "Widget.h"
#include "Borders/Frame.h"
#include "Borders/Frames.h"
#include "Colors/Colors.h"
#include "src/Console.h"

namespace Widget {
    class TextMessage : public widget {
    public:
        explicit TextMessage(const std::string &message);
        explicit TextMessage(const std::string &message,Color::COLOR);
        std::string GetText() {
            return text;
        }

        void PrintTextMessage() const {
            std::cout<<GetFrame(BORDER)->GetLine()<<'\t'<<text<<"\t"<<std::endl;
        }

    private:
        std::string text;
    };
}

#endif // TEXTMESSAGE_H
