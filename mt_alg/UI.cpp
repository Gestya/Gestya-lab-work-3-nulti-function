#include "UI.h"
#include "rndstr.h"

Widget* buildRandomUI(int& cnt, Widget* parent /* = nullptr */)
{
    if (cnt <= 0)
        return nullptr;

    if (!parent) // it will be the main window
    {
        Widget* main_window = new Window();
        main_window->setPosition({ 0, 0 });
        main_window->setSize({ 320, 200 });
        main_window->setName("Desktop");
        cnt--;
        while (cnt > 0)
            buildRandomUI(cnt, main_window);
        return main_window;
    }

    while (cnt > 0)
    {
        bool do_interrupt = (rand() % 10) == 0;
        if (do_interrupt)
            return nullptr;

        bool is_window = (rand() % 5) == 0;
        if (is_window)
        {
            Widget* window = new Window(parent);
            window->setPosition({ rand(), rand() });
            window->setSize({ rand(), rand() });
            window->setName(randomString(5, 30));
            cnt--;
            buildRandomUI(cnt, window);
            break;
        }

        Widget* widget;
        int type = rand() % 3;
        switch (type)
        {
        case 0: // Label
            widget = new Label(parent);
            break;
        case 1: // Button
            widget = new Button(parent);
            break;
        case 2: // EditLine
            widget = new EditLine(parent);
            break;
        default:
            throw std::exception(); // something went really wrong!!!
        }
        cnt--;
        widget->setPosition({ rand(), rand() });
        widget->setSize({ rand(), rand() });
        widget->setName(randomString(5, 30));
    }
}