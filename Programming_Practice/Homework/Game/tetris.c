#include <stdio.h>
#include <stdlib.h>
#define HEIGHT 14
#define WIDTH 18
#define clearScreen() printf("\033[2J")
#define moveCursor(x, y) printf("\033[%d;%dH", (x), (y))
void print_surface(void);
int surface[HEIGHT][WIDTH] = {0};

int main(void) {
    system("clear");
    print_surface();
    getchar();
    return 0;
}

void printxy(char* str, int x, int y) {
    moveCursor(x, y);
    printf("%s", str);
}

void print_surface(void) {
    int x, y;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            int row = y;
            int col = x;
            if (surface[row][col] == 0) {
                printxy("0", x, y);
            } else {
                printxy("1", x, y);
            }
        }
    }
}

void setCursorVisable(int v) {
    printf("\033[?25%c", v ? 'h' : 'l');
}