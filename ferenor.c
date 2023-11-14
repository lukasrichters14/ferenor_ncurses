#include "ferenor.h"

int handle_quit(char c, bool mode, WINDOW* w)
{
    if (mode && c == 'q')
    {
        return 2;
    } 
    else if (mode) 
    {
        mvwaddstr(w, 0, 0, "                                                     ");
        wrefresh(w);
        return 0;
    }

    if (c == KEY_F(1) || c == MS_KEY_F1)
    {
        mvwaddstr(w, 0, 0, "Press q to quit. Press any other key to continue");
        wrefresh(w);
        return 1;
    }

    return 0;
}

int main()
{
    initscr();
    refresh();  // This needs to be here to make the windows appear.
    cbreak();
    noecho();

    WINDOW *active_win;
    WINDOW *name_win = create_name_entry_window();
    WINDOW *avatar_win = create_avatar_window();
    WINDOW *class_win = create_class_window();
    WINDOW *stat_win = create_stats_window();
    WINDOW *help_win = create_help_window();
    WINDOW *tip_win = create_tip_window();

    keypad(stdscr, TRUE);
    keypad(name_win, TRUE);
    keypad(avatar_win, TRUE);
    keypad(class_win, TRUE);
    keypad(stat_win, TRUE);
    keypad(help_win, TRUE);
    keypad(tip_win, TRUE);

    wmove(name_win, 1, 7);
    wrefresh(name_win);

    active_win = name_win;
    int cursorx, cursory;
    cursorx = 7;
    cursory = 1;

    char c;
    int quit_mode = 0;
    while (true)
    {
        c = wgetch(active_win);

        quit_mode = handle_quit(c, quit_mode, tip_win);
        if (quit_mode == 2)
            break;
        else if (quit_mode == 1)
            continue;

        if (active_win == name_win)
        {
            if (c == KEY_BACKSPACE || c == MS_KEY_BACKSPACE)
            {
                cursorx--;
                mvwaddch(name_win, cursory, cursorx, ' ');
                wmove(name_win, cursory, cursorx);
            }
            else 
            {
                mvwaddch(name_win, cursory, cursorx, c);
                cursorx++;
            }
            wrefresh(name_win);
        }
    }

    delwin(name_win);
    delwin(avatar_win);
    delwin(class_win);
    delwin(stat_win);
    delwin(help_win);
    delwin(tip_win);
    endwin();
    return 0;
}

