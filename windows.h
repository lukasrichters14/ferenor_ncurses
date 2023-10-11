#ifndef _FERENOR_WINDOWS
#define _FERENOR_WINDOWS

#include <ncurses.h>

WINDOW* create_window(int height, int width, int y, int x);

void create_name_entry_window(WINDOW *win);

void create_avatar_window(WINDOW *win);

#endif