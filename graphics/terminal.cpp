#include "terminal.h"

/*
    Constructor for terminal. get the current width and height of the terminal window using ioctl header.
*/
terminal::terminal(char background) {
    winsize ws;
    ioctl(0, TIOCGWINSZ, &ws);

    this->width = ws.ws_col;
    this->height = ws.ws_row;
    this->background = background;

    screen = new vector()
}

/*
    filling the terminal with char c. using cout and the height-width defenition.
*/
void terminal::fill(char c) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            cout << c;
        }
        cout << "\n";
    }
}

/*
    cleaning the terminal by calling fill with the background character.
*/
void terminal::clean() {
    fill(background);
}

/*
    setting the pixel at the give location to be c.
*/
void terminal::set(vector2d pixel, char c) {
    clean();

}