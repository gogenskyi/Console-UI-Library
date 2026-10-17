#ifndef GLIB_LIBRARY_H
#define GLIB_LIBRARY_H
#include <memory>
#include <vector>
#define DEBUG
#include <iostream>

#include "Widget/Widget.h"


class Console {
public:
    static void CreateApplication(const std::vector<std::unique_ptr<widget>> &);
    static void UpdateState();
private:
    inline static std::vector<std::unique_ptr<widget>> context;

};

#endif // GLIB_LIBRARY_H
