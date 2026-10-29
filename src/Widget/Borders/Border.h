//
// Created by Mykola on 17.10.2026.
//

#ifndef GOGENSKYI_CUI_BORDER_H
#define GOGENSKYI_CUI_BORDER_H
#include "Frame.h"
#include "../Gogenskyi_CUI/src/Widget/Borders/Frame.h"

class Border : public Frame  {
public:
    explicit Border(const std::string &line) {
        this->line = line;
    }
    std::string line;
};


#endif //GOGENSKYI_CUI_BORDER_H
