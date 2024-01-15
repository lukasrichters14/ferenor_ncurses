#include "ferenor.h"

int main()
{
    initscr();
    refresh();  // This needs to be here to make the windows appear.
    cbreak();
    noecho();
    start_color();

    init_pair(NORMAL_TEXT, COLOR_WHITE, COLOR_BLACK);
    init_pair(HIGHLIGHT_TEXT, COLOR_BLACK, COLOR_WHITE);

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
    struct WindowStatus status;
    int cursorx, cursory;
    cursorx = 7;
    cursory = 1;

    char c;
    bool is_in_select_mode = false;
    while (true)
    {
        c = wgetch(active_win);

        if (c == KEY_STAB || c == MS_KEY_TAB)
            is_in_select_mode = true;
        
        if (is_in_select_mode)
        {
            highlight_window(active_win);
            mvwaddstr(tip_win, 0, 0, "ENTER: Select; ARROW: Move; Q: Quit");
            wrefresh(tip_win);
            if (c == 'q' || c == 'Q')
                break;
            else if (c == KEY_ENTER || c == MS_KEY_ENTER)
            {
                is_in_select_mode = false;
                mvwaddstr(tip_win, 0, 0, "                                            ");
                mvwaddstr(tip_win, 0, 0, "TAB: Control mode; ARROW: Move");
                wrefresh(tip_win);
                unhighlight_window(active_win);

                if (active_win == name_win)
                {
                    cursory = 1;
                    cursorx = 7;
                    wmove(name_win, cursory, cursorx);
                }
                else if (active_win == class_win || active_win == stat_win)
                {
                    cursory = 3;
                    cursorx = 1;
                    wmove(active_win, cursory, cursorx);
                    // memset(scr_text, '0', sizeof(scr_text));
                    // mvwinchstr(active_win, cursory, cursorx, scr_text);
                    // highlight_text_chtype(active_win, scr_text, cursory, cursorx);
                }

                wrefresh(active_win);
            }
            else if (active_win == name_win)
            {
                if (c == KEY_DOWN || c == MS_KEY_DOWN)
                {
                    unhighlight_window(active_win);
                    active_win = avatar_win;
                }
                else if (c == KEY_RIGHT || c == MS_KEY_RIGHT)
                {
                    unhighlight_window(active_win);
                    active_win = class_win;
                }
                highlight_window(active_win);
            }
            else if (active_win == avatar_win)
            {
                if (c == KEY_UP || c == MS_KEY_UP)
                {
                    unhighlight_window(active_win);
                    active_win = name_win;
                }
                else if (c == KEY_RIGHT || c == MS_KEY_RIGHT)
                {
                    unhighlight_window(active_win);
                    active_win = class_win;
                }
                highlight_window(active_win);
            }
            else if (active_win == class_win)
            {
                if (c == KEY_LEFT || c == MS_KEY_LEFT)
                {
                    unhighlight_window(active_win);
                    active_win = name_win;
                }
                else if (c == KEY_RIGHT || c == MS_KEY_RIGHT)
                {
                    unhighlight_window(active_win);
                    active_win = stat_win;
                }
                highlight_window(active_win);
            }
            else if (active_win == stat_win)
            {
                if (c == KEY_LEFT || c == MS_KEY_LEFT)
                {
                    unhighlight_window(active_win);
                    active_win = class_win;
                }
                highlight_window(active_win);
            }
        }
        else
        {
            mvwaddstr(tip_win, 0, 0, "TAB: Control mode; ARROW: Move");
            wrefresh(tip_win);
            
            status.cursorx = cursorx;
            status.cursory = cursory;
            status.prev_char = c;
            
            if (active_win == name_win) { name_window(name_win, &status, MS_KEY_TAB); }
            else if (active_win == class_win) { class_window(class_win, &status, MS_KEY_TAB); }
            wrefresh(active_win);
            is_in_select_mode = true;
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
