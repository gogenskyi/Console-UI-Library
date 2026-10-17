//
// Created by Mykola on 17.10.2026.
//

#ifndef GOGENSKYI_CUI_BOTTOM_H
#define GOGENSKYI_CUI_BOTTOM_H
#include <string>

#include "Header.h"

    class Bottom : public Border {
    public:
        explicit Bottom(char symbol = '_') {
            for (auto i = 0; i < Size;i++) {
                line += '_';
            }
        }
    };


#endif //GOGENSKYI_CUI_BOTTOM_H
