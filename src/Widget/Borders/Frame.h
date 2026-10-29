//
// Created by Mykola on 19.10.2026.
//

#ifndef GOGENSKYI_CUI_FRAME_H
#define GOGENSKYI_CUI_FRAME_H
#include <memory>
#include <vector>


class Frame;

class Frame {
public:
    std::string line;
    // static std::vector<std::unique_ptr<Frame>> frame;
    inline static int Size;
    // enum FRAME {
    //     HEADER,
    //     BORDER,
    //     BOTTOM
    // };
    // static std::unique_ptr<Frame> GetFrame(const FRAME f) {
    //     switch (f) {
    //         case HEADER: return std::move(frame[HEADER]);
    //         case BORDER: return std::move(frame[BORDER]);
    //         case BOTTOM: return std::move(frame[BOTTOM]);
    //
    //     }
    //     return std::move(frame[BORDER]);
    // }

    std::string GetLine() const {
        return line;
    }
};

#endif //GOGENSKYI_CUI_FRAME_H
