#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include "mode_choice.h"
#include "file_io.h"
#include "display.h"

int main()
{
    int x_max, y_max;
    char buffer[60];
    char input[20];

    initscr();
    cbreak();
    refresh();
    curs_set(0);

    getmaxyx(stdscr, y_max, x_max);

    // Choose the mode and open a file
    WINDOW *choice_win = newwin(y_max, x_max, 0, 0);
    box(choice_win, 0, 0);
    mvwprintw(choice_win, 0, 3, "[ TEXT EDITOR ]");
    keypad(choice_win, true);
    refresh();
    wrefresh(choice_win);

    int mode = mode_choice(choice_win);

    char *modes[3] = {"r", "r+", "w+"};
    wrefresh(choice_win);
    char file_name[30];
    char ch;

    file_input(choice_win, file_name);
    FILE *file_ptr = fopen(file_name, modes[mode]);

    while (1)
    {
        if (file_ptr == NULL)
        {
            mvwprintw(choice_win, 4, 3, "ERROR OPENING FILE !");
            wrefresh(choice_win);
            getchar();
            file_input(choice_win, file_name);
            file_ptr = fopen(file_name, modes[mode]);
        }
        else
            break;
    }
    fclose(file_ptr);

    delwin(choice_win);

    // Display and/or edit file
    box(stdscr, 0, 0);
    mvprintw(0, 3, "[ %s ]", file_name);
    refresh();

    int lines = count_file_lines(file_ptr);

    WINDOW *text_pad = newpad(500, x_max - 4);
    keypad(text_pad, true);
    prefresh(text_pad, 0, 0, 2, 2, y_max - 3, x_max - 4);

    switch (mode)
    {
    case 0:
        read_file(file_ptr, text_pad, x_max, y_max, file_name);
        break;

    default:
        break;
    }

    getchar();
    endwin();
}
