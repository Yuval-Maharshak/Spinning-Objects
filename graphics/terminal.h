#include "head.h"
#include <sys/ioctl.h>
#include <ncurses.h>

class screen {
    public:
        char **matrix;
        int width;
        int height;
        char bc;

        /*
            creating a screen.
            @param background_color the default character to fill the background.
            @param width the width of the screen.
            @param height the height of the screen
        */
        screen(char background_color, int width, int height);

        void fill(char color);
        void reset();
};

class terminal {
    public:
        screen *win;

        /*
            creating a terminal by the current terminal window dimentions.
            @param background_color the default character to fill the background.
        */
        terminal(char background_color); 

        /*
            deleting the old screen and printing the current to the terminal.
        */
        void printScreen();

        void terend();
};