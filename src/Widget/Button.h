//
// Created by Mykola on 17.10.2026.
//

#ifndef GOGENSKYI_CUI_BUTTON_H
#define GOGENSKYI_CUI_BUTTON_H
#include <functional>
#include <memory>

#include "Widget.h"

namespace Widget {
    class Button : public widget {
        std::string Command;
        std::unique_ptr<std::function<void()>> func_ptr;
    public:
        Button(const std::function<void()>&,std::string, const std::string &);
    };

}


#endif //GOGENSKYI_CUI_BUTTON_H
