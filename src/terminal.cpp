#include "terminal.h"

/* terminal implementation */

terminal::terminal(char background_color) {
    winsize ws;
    ioctl(0, TIOCGWINSZ, &ws);  /* finding the terminal window size */

    win = new screen(background_color, ws.ws_col, ws.ws_row - 1);   /* creating a new screen leaving 1 row for input */

    initscr();      /* starting ncurses */
}
terminal::terminal() {
    winsize ws;
    ioctl(0, TIOCGWINSZ, &ws);  /* finding the terminal window size */

    win = new screen('#', ws.ws_col, ws.ws_row - 1);   /* creating a new screen leaving 1 row for input */

    initscr();      /* starting ncurses */
}

void terminal::printScreen() {
    int i,j;        /* indexes */
    clear();        /* clearing the current screen */
    for (i = 0; i < win->height; i++) {
        for (j = 0; j<win->width; j++) {
            addch(win->matrix[i][j]);
        }
    }

    addstr("> ");       /* input line */

    refresh();      /* ncurses works on a buffer */
}

void terminal::terend() {
    endwin();       /* ending ncurses */
}

bool terminal::getInput(string line) {
    line = getInputPrimitive();
    return line.compare("stop") != 0;
}

char * terminal::getInputPrimitive() {
    char *line = (char *) malloc(50);
    
    getnstr(line, 50);

    move(getcury(stdscr), 2);
    clrtoeol();
    refresh();

    return line;
}

/* screen implementation*/

screen::screen(char background_color, int width, int height) {
    this->width = width;
    this->height = height;

    int i,j;        /* indexes */

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
    int i,j;        /* indexes */

    for (i = 0; i < height; i++) {
        for (j = 0; j<width; j++) {
            matrix[i][j] = color; 
        }
    }
}

void screen::reset() {
    fill(bc);       /* bc = background color */
}