#ifndef _FERENOR
#define _FERENOR

#include <ncurses.h>
#include "windows.h"

// The following constants are necessary for using ncurses on a windows system.
#define MS_KEY_BACKSPACE '\a'
#define MS_KEY_DOWN '\002'
#define MS_KEY_UP '\003'
#define MS_KEY_LEFT '\004'
#define MS_KEY_RIGHT '\005'
#define MS_KEY_ESC '\033'
#define MS_KEY_ENTER '\n'
#define MS_KEY_F1 '\t'

int handle_quit(char c, bool mode, WINDOW* w);

#endif