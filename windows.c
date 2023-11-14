#include "windows.h"

WINDOW* create_window(int height, int width, int y, int x, bool border)
{
    WINDOW* win = newwin(height, width, y, x);
    if (border)
        wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(win);
    return win;
}

WINDOW* create_name_entry_window()
{
    WINDOW* w = create_window(3, 28, 0, 0, true);
    mvwaddstr(w, 1, 1, "Name: ");
    //mvwprintw(name_win, 1, 1, "%d %d", LINES, COLS);
    wrefresh(w);
    return w;
}

WINDOW* create_avatar_window()
{
    WINDOW* w = create_window(19, 28, 5, 0, true);
    mvwaddstr(w, 1, 1, "Character Appearance");
    mvwaddstr(w, 3, 12, "####");
    mvwaddstr(w, 4, 12, "####");
    mvwaddstr(w, 5, 12, "####");
    mvwaddstr(w, 6, 13,  "##");
    mvwaddstr(w, 7, 10, "########");
    mvwaddstr(w, 8, 9, "##########");
    mvwaddstr(w, 9, 8, "##  ####  ##");
    mvwaddstr(w, 10, 7, "##   ####   ##");
    mvwaddstr(w, 11, 12, "####");
    mvwaddstr(w, 12, 11, "######");
    mvwaddstr(w, 13, 11, "##  ##");
    mvwaddstr(w, 14, 11, "##  ##");
    mvwaddstr(w, 15, 11, "##  ##");
    mvwaddstr(w, 16, 11, "##  ##");
    wrefresh(w);
    return w;
}

WINDOW* create_class_window()
{
    WINDOW* w = create_window(9, 19, 0, 35, true);
    mvwaddstr(w, 1, 1, "Class Selection");
    mvwaddstr(w, 3, 1, "Druid");
    mvwaddstr(w, 4, 1, "Mage");
    mvwaddstr(w, 5, 1, "Rogue");
    mvwaddstr(w, 6, 1, "Warrior");
    wrefresh(w);
    return w;
}

WINDOW* create_stats_window()
{
    WINDOW* w = create_window(9, 19, 0, 60, true);
    mvwaddstr(w, 1, 1, "Character Stats");
    mvwaddstr(w, 3, 1, "HP       : ");
    mvwaddstr(w, 4, 1, "Magic    : ");
    mvwaddstr(w, 5, 1, "Speed    : ");
    mvwaddstr(w, 6, 1, "Strength : ");
    wrefresh(w);
    return w;
}

WINDOW* create_help_window()
{
    WINDOW* w = create_window(13, 44, 11, 35, true);
    mvwaddstr(w, 1, 1, "Description");
    wrefresh(w);
    return w;
}

WINDOW* create_tip_window()
{
    WINDOW* w = create_window(3, 60, 25, 0, false);
    wrefresh(w);
    return w;
}