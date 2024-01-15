#ifndef _FERENOR_WIN_STATUS
#define _FERENOR_WIN_STATUS

#include <ncurses.h>

struct WindowStatus
{
    WINDOW* w;
    WINDOW* help_w;
    int cursorx;
    int cursory;
    char prev_char;
};

typedef struct WindowStatus WindowStatus;

#endif