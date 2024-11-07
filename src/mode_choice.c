#include <ncurses.h>
#include "mode_choice.h"

int mode_choice(WINDOW *choice_win)
{
    char modes[3][20] = {"[+] READ A FILE", "[+] EDIT A FILE", "[+] NEW FILE"};
    int mode;
    int highlight = 0;

    while (1)
    {
        for (int i = 0; i < 3; i++)
        {
            if (i == highlight)
                wattron(choice_win, A_REVERSE);

            mvwprintw(choice_win, (i * 2) + 2, 3, "%s", modes[i]);
            wattroff(choice_win, A_REVERSE);
        }

        mode = wgetch(choice_win);

        switch (mode)
        {
        case KEY_UP:
            highlight--;

            if (highlight < 0)
                highlight = 0;
            break;

        case KEY_DOWN:
            highlight++;

            if (highlight > 2)
                highlight = 2;
            break;

        default:
            break;
        }

        if (mode == 10)
        {
            break;
        }
    }

    return highlight;
}
