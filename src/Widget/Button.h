//
// Created by Mykola on 17.10.2026.
//

#ifndef GOGENSKYI_CUI_BUTTON_H
#define GOGENSKYI_CUI_BUTTON_H
#include <functional>
#include <iostream>
#include <memory>

#include "Widget.h"
#include "Borders/Frame.h"
#include "src/Console.h"

namespace Widget {
    class Button : public widget {
        std::string Command;
        std::unique_ptr<std::function<void()>> func_ptr;
        std::string text;
    public:
        std::unique_ptr<std::function<void()>> GetFuncPtr();
        std::string GetCommand() {
            return Command;
        }
        void PrintButton() const {
            std::cout<<Frame::GetFrame(Frame::BORDER)->GetLine()<<"  "<<Command<<":  "<<text<<'\t';
        }
        Button(const std::function<void()>&,std::string, const std::string &);
    };
}


#endif //GOGENSKYI_CUI_BUTTON_H
