//
// Created by Mykola on 17.10.2026.
//

#ifndef GOGENSKYI_CUI_HEADER_H
#define GOGENSKYI_CUI_HEADER_H
#include <string>

#include "Border.h"

    class Header : public Frame {
        std::string title;
    public:
        Header(const std::string &title, const int size) {
            if (size < 15) {
                throw std::invalid_argument("Exception: size must be at least 15");
            }
            Size = size;
            this->title = title;
            line.clear();
            line += "_" + title;
            for (auto i = 0;i < size - title.size();i++) {
                line += '_';
            }
        }
    };

#endif //GOGENSKYI_CUI_HEADER_H
