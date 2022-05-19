#include <ncurse.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    initscr();
    move(5, 10);
    printw("Hello World!");
    refresh();
    endwin();
}