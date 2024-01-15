#ifndef _FERENOR_WINDOWS
#define _FERENOR_WINDOWS

#include <ncurses.h>
#include <string.h>
#include "window_status.h"
#include "keys.h"

#define NORMAL_TEXT 1
#define HIGHLIGHT_TEXT 2
#define HELP_WIN_WIDTH 44
#define HELP_WIN_HEIGHT 13

WINDOW* create_window(int height, int width, int y, int x, bool boarder);

WINDOW* create_name_entry_window();

WINDOW* create_avatar_window();

WINDOW* create_class_window();

WINDOW* create_stats_window();

WINDOW* create_help_window();

WINDOW* create_tip_window();

void name_window(WINDOW* w, WindowStatus* status, char return_char);

void class_window(WINDOW* w, WindowStatus* status, char return_char);

void highlight_window(WINDOW* w);

void unhighlight_window(WINDOW* w);

void highlight_text(WINDOW* w, char* text, int y, int x);

void unhighlight_text(WINDOW* w, char* text, int y, int x);

void highlight_text_chtype(WINDOW* w, chtype* text, int y, int x);

void unhighlight_text_chtype(WINDOW* w, chtype* text, int y, int x);

void get_char_from_chtype(chtype* txt, char* text);

void write_string_to_window(WINDOW* w, char* s);

int chtype_strcmp(chtype* s1, const char* s2);

#endif