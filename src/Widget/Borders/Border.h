//
// Created by Mykola on 17.10.2026.
//

#ifndef GOGENSKYI_CUI_BORDER_H
#define GOGENSKYI_CUI_BORDER_H


class Border {
public:
    inline static int Size;
    std::string line = "|";

    std::string GetLine() const {
        return line;
    }
};


#endif //GOGENSKYI_CUI_BORDER_H
