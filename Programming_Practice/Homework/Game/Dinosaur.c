#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
#define CANVAS 50
void display(char[], int, int);
void shiftLeft(char *, int);
void changemode(int);
int kbhit(void);

int main() {
    int playerPos = 6;
    int sleeptime = 200000;
    int jump_time = 0;
    int score = 0;
    int delay = 0;
    char floor1[CANVAS], floor2[CANVAS];
    for (int i = 0; i < CANVAS; i++) {
        floor1[i] = '_';
        floor2[i] = ' ';
    }
    int current_floor = 1;
    srand(time(NULL));
    bool stop = false;
    while (1) {
        changemode(1);
        while (!kbhit()) {
            printf("\n\tScore: %d\n", score);
            if (!(score++ % 10)) {
                floor1[CANVAS - (rand() % 5 + 1)] = 'X';
            }
            if (current_floor == 1 || (current_floor == 2 && delay == 1)) {
                if (floor1[playerPos] == 'X') {
                    printf("\n\tGame Over!\n\n");
                    return 0;
                }
                printf("\n\n\t");
                display(floor2, 0, CANVAS);
                printf("\n\t");
                display(floor1, 0, playerPos);
                printf("0");
                display(floor1, playerPos + 1, CANVAS);
                printf("\n\n");
                delay = 0;
            } else if (current_floor == 2 && delay == 0) {
                if (jump_time++ > 1) {
                    jump_time = 0;
                    current_floor = 1;
                    delay = 1;
                }
                printf("\n\n\t");
                display(floor2, 0, playerPos);
                printf("0");
                display(floor2, playerPos + 1, CANVAS);
                printf("\n\t");
                display(floor1, 0, CANVAS);
                printf("\n\n");
            }
            shiftLeft(floor1, CANVAS);
            usleep(sleeptime);
            system("clear");
        }
        if (getchar() == ' ') {
            current_floor = 2;
        }
        changemode(0);
    }
    return 0;
}

void display(char *floor, int lowerlimit, int upperlimit) {
    for (int i = lowerlimit; i < upperlimit; i++) {
        printf("%c", floor[i]);
    }
}

void shiftLeft(char *floor, int upperlimit) {
    for (int i = 0; i < upperlimit - 1; i++) {
        floor[i] = floor[i + 1];
    }
    floor[upperlimit - 1] = '_';
}

void changemode(int dir) {
    static struct termios oldt, newt;
    if (dir == 1) {
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    } else
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

int kbhit(void) {
    struct timeval tv;
    fd_set rdfs;

    tv.tv_sec = 0;
    tv.tv_usec = 0;

    FD_ZERO(&rdfs);
    FD_SET(STDIN_FILENO, &rdfs);

    select(STDIN_FILENO + 1, &rdfs, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &rdfs);
}