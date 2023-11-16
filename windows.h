#ifndef _FERENOR_WINDOWS
#define _FERENOR_WINDOWS

#include <ncurses.h>

WINDOW* create_window(int height, int width, int y, int x, bool boarder);

WINDOW* create_name_entry_window();

WINDOW* create_avatar_window();

WINDOW* create_class_window();

WINDOW* create_stats_window();

WINDOW* create_help_window();

WINDOW* create_tip_window();

void highlight_window(WINDOW* w);

void unhighlight_window(WINDOW* w);

#endif