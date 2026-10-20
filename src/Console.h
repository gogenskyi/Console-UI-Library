#ifndef GLIB_LIBRARY_H
#define GLIB_LIBRARY_H
#include <memory>
#include <vector>
#define DEBUG
#include <iostream>

#include "Widget/Button.h"
#include "Widget/TextMessage.h"
#include "Widget/Widget.h"
#include "Widget/Borders/Border.h"


class Console {
public:
    static void CreateApplication(const std::string &page_name,std::vector<std::unique_ptr<widget>> &);
    static void UpdateState();
private:
    inline static std::vector<std::unique_ptr<widget>> buttons;
    inline static std::vector<std::unique_ptr<widget>> text_messages;
    inline static std::vector<std::unique_ptr<widget>> context;
    static void ExeсuteFunc(const std::string &);
    static void PrintButtons();
    static std::string Input();
protected:
    inline static std::string page_title;
};

#endif // GLIB_LIBRARY_H
