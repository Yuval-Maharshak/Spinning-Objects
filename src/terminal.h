#include "head.h"
#include <sys/ioctl.h>
#include <ncurses.h>

/*
    A class to represent the screen and it's char matrix.
*/
class screen {
    public:
        char **matrix;      /* screen matrix */
        int width;          /* matrix width in characters */
        int height;         /* matrix height in characters */
        char bc;            /* the default background color of the screen */

        /*
            creating a screen.
            @param background_color the default character to fill the background.
            @param width the width of the screen.
            @param height the height of the screen
        */
        screen(char background_color, int width, int height);
        
        /*
            filling the screen with the character color.
        */
        void fill(char color);

        /*
            restoring the screen to the first frame (filling with background color).
        */
        void reset();
};

/*
    A class to represent the terminal and it's functions.
*/
class terminal {
    public:
        screen *win;        /* the screen of the terminal */

        /*
            creating a terminal by the current terminal window dimentions.
            @param background_color the default character to fill the background.
        */
        terminal(char background_color); 

        /*
            creating a terminal by the current terminal window dimentions.
        */
        terminal();

        /*
            deleting the old screen and printing the current to the terminal.
        */
        void printScreen();

        /*
            ending the terminal operation.
        */
        void terend();

        bool getInput(string line);

        char * getInputPrimitive();
};