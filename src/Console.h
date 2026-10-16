#ifndef GLIB_LIBRARY_H
#define GLIB_LIBRARY_H
#include <vector>

#include "Widget/Widget.h"

class Console {
public:
    bool Actual = false;
    static void CreateApplication(const std::vector<widget> &);
    static void UpdateState();
private:
    inline static std::vector<widget> context;

};

#endif // GLIB_LIBRARY_H
