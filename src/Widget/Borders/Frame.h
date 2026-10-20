//
// Created by Mykola on 19.10.2026.
//

#ifndef GOGENSKYI_CUI_FRAME_H
#define GOGENSKYI_CUI_FRAME_H
#include <memory>
#include <vector>

#include "Border.h"

class Frame {
public:
    inline static std::vector<std::unique_ptr<Border>> frame;
    enum FRAME {
        HEADER,
        BORDER,
        BOTTOM
    };
    static std::unique_ptr<Border> GetFrame(const FRAME f) {
        // refactor all borders
        switch (f) {
            case HEADER: return std::move(frame[HEADER]);
            case BORDER: return std::move(frame[BORDER]);
            case BOTTOM: return std::move(frame[BOTTOM]);

        }
        return std::move(frame[BORDER]);
    }
};

#endif //GOGENSKYI_CUI_FRAME_H
