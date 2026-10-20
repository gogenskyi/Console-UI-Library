//
// Created by Mykola on 16.10.2026.
//

#ifndef GLIB_WIDGET_H
#define GLIB_WIDGET_H
#include <string>
    class widget {
    public:
        virtual ~widget() = default;
        void SetText(const std::string& text);
    };

#endif //GLIB_WIDGET_H
