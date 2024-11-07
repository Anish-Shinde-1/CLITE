#ifndef DISPLAY_H
#define DISPLAY_H

#include <ncurses.h>

void read_file(FILE *file_ptr, WINDOW *text_pad, int x_max, int y_max, char file_name[30]);

#endif
