#include "terminal.h"
#include "head.h"
#include <unistd.h>

int main () {
    terminal t('*');

    t.printScreen();

    t.win->fill('#');
    t.printScreen();

    t.terend();
}