#ifndef GLIB_LIBRARY_H
#define GLIB_LIBRARY_H
#include <memory>
#include <vector>
#define DEBUG
#include <iostream>

#include "Widget/Widget.h"
#include "Widget/Borders/Border.h"


class Console {
public:
    static void CreateApplication(const std::string &page_name,const std::vector<std::unique_ptr<widget>> &);
    static void UpdateState();
private:
    inline static std::vector<std::unique_ptr<widget>> context;
    inline static std::vector<std::unique_ptr<Border>> frame;
protected:
    inline static std::string page_title = "Title";
};

#endif // GLIB_LIBRARY_H
