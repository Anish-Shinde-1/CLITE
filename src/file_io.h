#ifndef FILE_IO_H
#define FILE_IO_H

#include <ncurses.h>

void file_input(WINDOW *choice_win, char file_name[30]);
int count_file_lines(FILE *file_ptr);

#endif
