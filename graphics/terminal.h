#include "head.h"
#include "math.h"
#include <fstream>
#include <vector>

#include <sys/ioctl.h>

class terminal {
    private:
        int width;      /* width of terminal in chars */
        int height;     /* height of terminal in chars */
        char background;
        vector<vector<char>> *screen ;
    
    public:
        terminal(char background);     /* constructor declaration*/

        /*
            fills the screen with the character c.
        */
        void fill(char c);

        /*
            fills the screen with the background.
        */
        void clean();

        /*
            set the pixel at the give location to be c
        */
        void set(vector2d pixel, char c);
};