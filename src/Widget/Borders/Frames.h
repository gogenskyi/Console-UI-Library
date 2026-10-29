//
// Created by Mykola on 29.10.2026.
//

#ifndef GOGENSKYI_CUI_FRAMES_H
#define GOGENSKYI_CUI_FRAMES_H
#include <algorithm>

#include "Frame.h"


inline static std::vector<std::unique_ptr<Frame>> frame;
   enum FRAME {
       HEADER,
       BORDER,
       BOTTOM
   };
   static std::unique_ptr<Frame> GetFrame(const FRAME f) {
       switch (f) {
           case HEADER: return std::move(frame[HEADER]);
           case BORDER: return std::move(frame[BORDER]);
           case BOTTOM: return std::move(frame[BOTTOM]);

       }
       return std::move(frame[BORDER]);
   }

#endif //GOGENSKYI_CUI_FRAMES_H
