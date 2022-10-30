#include "terminal.h"

/* terminal implementation */

terminal::terminal(char background_color) {
    winsize ws;
    ioctl(0, TIOCGWINSZ, &ws);  /* finding the terminal window size */

    win = new screen(background_color, ws.ws_col, ws.ws_row - 1);

    initscr();
}

void terminal::printScreen() {
    int i,j;
    clear();
    for (i = 0; i < win->height; i++) {
        for (j = 0; j<win->width; j++) {
            addch(win->matrix[i][j]);
        }
    }
    refresh();
}

void terminal::terend() {
    addstr("enter any character to end...");
    refresh();

    getch();

    endwin();
}

/* screen implementation*/

screen::screen(char background_color, int width, int height) {
    this->width = width;
    this->height = height;

    int i,j;

    /* allocation memory to the matrix */
    matrix = new char*[height];
    for (i = 0; i < height; i++) {
        matrix[i] = new char[width];
    }

    /* filling the matrix with background_color */
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            matrix[i][j] = background_color;
        }
    }
}

void screen::fill(char color) {
    int i,j;

    for (i = 0; i < height; i++) {
        for (j = 0; j<width; j++) {
            matrix[i][j] = color; 
        }
    }
}

void screen::reset() {
    fill(bc);
}