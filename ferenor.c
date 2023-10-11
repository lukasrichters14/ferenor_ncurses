#include "ferenor.h"

int main()
{
    initscr();
    refresh();  // This needs to be here to make the windows appear.
    raw();
    noecho();
    keypad(stdscr, TRUE);

    WINDOW *name_win = create_window(3, 28, 0, 0);
    WINDOW *avatar_win = create_window(20, 28, 5, 0);
    WINDOW *class_win = create_window(9, 19, 0, 35);
    WINDOW *stat_win = create_window(9, 19, 0, 60);
    WINDOW *help_win = create_window(14, 44, 11, 35);

    //mvwaddstr(name_win, 1, 1, "Name: ");
    mvwprintw(name_win, 1, 1, "%d %d", LINES, COLS);
    wrefresh(name_win);

    mvwaddstr(class_win, 1, 1, "Class Selection");
    mvwaddstr(class_win, 3, 1, "Druid");
    mvwaddstr(class_win, 4, 1, "Mage");
    mvwaddstr(class_win, 5, 1, "Rogue");
    mvwaddstr(class_win, 6, 1, "Warrior");
    wrefresh(class_win);

    mvwaddstr(stat_win, 1, 1, "Character Stats");
    mvwaddstr(stat_win, 3, 1, "HP       : ");
    mvwaddstr(stat_win, 4, 1, "Magic    : ");
    mvwaddstr(stat_win, 5, 1, "Speed    : ");
    mvwaddstr(stat_win, 6, 1, "Strength : ");
    wrefresh(stat_win);

    mvwaddstr(help_win, 1, 1, "Description");
    wrefresh(help_win);

    mvwaddstr(avatar_win, 1, 1, "Character Appearance");
    mvwaddstr(avatar_win, 4, 12, "####");
    mvwaddstr(avatar_win, 5, 12, "####");
    mvwaddstr(avatar_win, 6, 12, "####");
    mvwaddstr(avatar_win, 7, 13,  "##");
    mvwaddstr(avatar_win, 8, 10, "########");
    mvwaddstr(avatar_win, 9, 9, "##########");
    mvwaddstr(avatar_win, 10, 8, "##  ####  ##");
    mvwaddstr(avatar_win, 11, 7, "##   ####   ##");
    mvwaddstr(avatar_win, 12, 12, "####");
    mvwaddstr(avatar_win, 13, 11, "######");
    mvwaddstr(avatar_win, 14, 11, "##  ##");
    mvwaddstr(avatar_win, 15, 11, "##  ##");
    mvwaddstr(avatar_win, 16, 11, "##  ##");
    mvwaddstr(avatar_win, 17, 11, "##  ##");
    
    wrefresh(avatar_win);

    char c;
    while ((c = getch()) != 'q')
    {

    }

    delwin(name_win);
    delwin(avatar_win);
    delwin(class_win);
    delwin(stat_win);
    delwin(help_win);
    endwin();
    return 0;
}

