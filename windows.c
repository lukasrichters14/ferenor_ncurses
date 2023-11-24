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
    mvwaddstr(w, 0, 0, "TAB: Control mode; ARROW: Move");
    wrefresh(w);
    return w;
}

void highlight_window(WINDOW* w)
{
    wborder(w, '#', '#', '#', '#', '+', '+', '+', '+');
    wrefresh(w);
}

void unhighlight_window(WINDOW* w)
{
    wborder(w, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(w);
}

void highlight_text(WINDOW* w, char* text, int y, int x)
{
    wattron(w, COLOR_PAIR(HIGHLIGHT_TEXT));
    mvwaddstr(w, y, x, text);
    wattroff(w, COLOR_PAIR(HIGHLIGHT_TEXT));
    wrefresh(w);
}

void unhighlight_text(WINDOW* w, char* text, int y, int x)
{
    wattron(w, COLOR_PAIR(NORMAL_TEXT));
    mvwaddstr(w, y, x, text);
    wattroff(w, COLOR_PAIR(NORMAL_TEXT));
    wrefresh(w);
}

void highlight_text_chtype(WINDOW* w, chtype* text, int y, int x)
{
    char t[25];
     (text, t);
    highlight_text(w, t, y, x);
}

void unhighlight_text_chtype(WINDOW* w, chtype* text, int y, int x)
{
    char t[25];
    get_char_from_chtype(text, t);
    unhighlight_text(w, t, y, x);
}

void get_char_from_chtype(chtype* to_convert, char* text)
{
    for (int i = 0; i < 25; i++)
    {
        text[i] = to_convert[i] & A_CHARTEXT;
    }
}

void write_string_to_window(WINDOW* w, char* s)
{
    int i = 0;
    int x = 1;
    int y = 1;
    while (s[i] != '\0')
    {
        mvwaddch(w, y, x, s[i]);
        i++;
        x++;
        if (x > HELP_WIN_WIDTH - 2)
        {
            mvwaddch(w, y, x, '-');
            x = 1;
            y++;
        }
    }
}

int chtype_strcmp(chtype* s1, const char* s2)
{

}