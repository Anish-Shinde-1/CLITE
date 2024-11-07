#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include "display.h"

void read_file(FILE *file_ptr, WINDOW *text_pad, int x_max, int y_max, char file_name[30])
{
    char buffer[1024];
    char temp_buffer[x_max - 9]; // 200 = 199 + null
    prefresh(text_pad, 0, 0, 2, 2, y_max - 3, x_max - 4);

    int ch;
    int highlight_line = 0;
    int start_line = 0;
    int end_line = y_max - 5;

    do
    {
        int index = 1;
        int line = 0;

        file_ptr = fopen(file_name, "r");

        while (fgets(buffer, sizeof(buffer) - 1, file_ptr) != NULL)
        {
            int len = strlen(buffer);

            if (len > (x_max - 10))
            {
                int printed = 0;
                while (len >= (x_max - 10))
                {
                    strncpy(temp_buffer, buffer + printed, (x_max - 10));
                    temp_buffer[(x_max - 9)] = '\0';

                    if (printed == 0)
                    {
                        if (line == highlight_line)
                        {
                            wattron(text_pad, A_STANDOUT);
                        }
                        mvwprintw(text_pad, line, 0, "%3d. %s", index, temp_buffer);
                        wattroff(text_pad, A_STANDOUT);
                    }
                    else
                    {
                        if (line == highlight_line)
                        {
                            wattron(text_pad, A_STANDOUT);
                        }
                        mvwprintw(text_pad, line, 0, "     %s", temp_buffer);
                        wattroff(text_pad, A_STANDOUT);
                    }

                    printed += (x_max - 10);
                    len -= (x_max - 10);
                    line++;
                }
                if (len > 0)
                {
                    strcpy(temp_buffer, buffer + printed);
                    temp_buffer[strlen(temp_buffer) - 1] = '\0';

                    if (line == highlight_line)
                    {
                        wattron(text_pad, A_STANDOUT);
                    }
                    mvwprintw(text_pad, line, 0, "     %s", temp_buffer);
                    wattroff(text_pad, A_STANDOUT);
                    line++;
                }
                index++;
            }
            else
            {
                if (len > 0 && buffer[len - 1] == '\n')
                {
                    buffer[len - 1] = '\0';
                }

                if (line == highlight_line)
                {
                    wattron(text_pad, A_STANDOUT);
                }

                mvwprintw(text_pad, line, 0, "%3d. %s", index, buffer);
                wattroff(text_pad, A_STANDOUT);
                index++;
                line++;
            }
        }
        fclose(file_ptr);
        prefresh(text_pad, start_line, 0, 2, 2, y_max - 3, x_max - 4);

        mvprintw(y_max - 1, (x_max - 60), "[ line : %3d / Total lines : %3d ]", highlight_line + 1, line);
        wrefresh(stdscr);

        noecho();
        ch = wgetch(text_pad);
        echo();

        switch (ch)
        {
        case KEY_UP:
            highlight_line--;
            if (highlight_line < 0)
                highlight_line = 0;
            if (highlight_line < start_line)
            {
                start_line--;
            }
            break;

        case KEY_DOWN:
            highlight_line++;
            if (highlight_line >= line)
                highlight_line = line - 1;

            if (highlight_line > (y_max - 5) && highlight_line < line)
            {
                start_line++;
            }

            if (start_line > line - (y_max - 5))
            {
                start_line = line - (y_max - 5);
            }
            break;

        default:
            break;
        }

    } while (ch != 27);
}
