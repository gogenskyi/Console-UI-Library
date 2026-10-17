//
// Created by Mykola on 17.10.2026.
//

#ifndef GOGENSKYI_CUI_COLORS_H
#define GOGENSKYI_CUI_COLORS_H
#include <vector>


static class Color {
public:
    static std::string GetColor(const int index) {
        switch (index) {
            case RED:
                return "\033[0;31m";
            case GREEN:
                return "\033[0;32m";
            case YELLOW:
                return "\033[0;33m";


            default: return "\033[0;30m";
        }
    }
    enum COLOR {
        RED,
        GREEN,
        YELLOW,
    };
};


#endif //GOGENSKYI_CUI_COLORS_H
