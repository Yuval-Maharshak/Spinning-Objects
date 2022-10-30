#include <ncurses.h>

int main() {
    initscr();

    int row = 25;
    int col = 25;

    curs_set(0);

    for (char c  = 65; c <= 90; c++) {
        mvaddch(row--, col--, c);
        refresh();
        napms(100);
    }

    curs_set(1);
    addch('\n');
    move(27, 0);
    printw("enter any char to continue \n");
    getch();

    endwin();
}