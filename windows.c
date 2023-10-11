#include "windows.h"

WINDOW* create_window(int height, int width, int y, int x)
{
    WINDOW* win = newwin(height, width, y, x);
    wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(win);
    return win;
}

void create_name_entry_window(WINDOW *win)
{

}

void create_avatar_window(WINDOW *win)
{

}

