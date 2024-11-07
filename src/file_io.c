#include <stdio.h>
#include "file_io.h"

void file_input(WINDOW *choice_win, char file_name[30])
{
    wclear(choice_win);
    box(choice_win, 0, 0);
    mvwprintw(choice_win, 0, 3, "[ TEXT EDITOR ]");
    mvwprintw(choice_win, 2, 3, "[+] FILE NAME : ");
    wrefresh(choice_win);
    curs_set(1);
    wgetnstr(choice_win, file_name, 29);
    curs_set(0);
}

int count_file_lines(FILE *file_ptr)
{
    char ch;
    int lines = 0;

    while (ch != EOF)
    {
        ch = fgetc(file_ptr);
        if (ch == '\n' || ch == EOF)
        {
            lines++;
        }
    }

    return lines;
}

