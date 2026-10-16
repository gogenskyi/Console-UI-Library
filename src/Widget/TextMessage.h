//
// Created by Mykola on 16.10.2026.
//

#ifndef GLIB_TEXTMESSAGE_H
#define GLIB_TEXTMESSAGE_H

#include <string>
#include "Widget.h"

namespace Widget {
    class TextMessage : public widget {
    public:
        explicit TextMessage(std::string message);

        TextMessage(std::string &message);

    private:
        const std::string console_message = "echo ";
    };
}

#endif //GLIB_TEXTMESSAGE_H
