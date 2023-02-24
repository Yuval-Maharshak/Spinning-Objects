#include "terminal.h"
#include "head.h"
#include "elemfunc.h"
#include <unistd.h>

int main () {
    terminal t;
    string eq;
    int n=10;
    while(n--) {
        t.printScreen();
        if (! t.getInput(eq)) {
            t.terend();
        }
        cout << eq;
    }
    t.terend();
}