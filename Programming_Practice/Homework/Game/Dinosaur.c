#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
#define CANVAS 50
#define PLAYERPOS 6
void display(char[], int, int);
void shiftLeft(char *, int);
bool isDead(char *, int, int);
void changemode(int);
int kbhit(void);

int main() {
    int sleeptime = 70000;
    int jump_time = 0;
    int score = 0;
    int ammo = 5;
    int delay = 0;
    char floor1[CANVAS], floor2[CANVAS];
    for (int i = 0; i < CANVAS; i++) {
        floor1[i] = '_';
        floor2[i] = ' ';
    }
    int current_floor = 1;
    srand(time(NULL));
    bool stop = false;
    printf("\tPress 'p' to pause the game\n");
    printf("\tPress 'w' to jump\n");
    printf("\tPress space to fire\n");
    printf("\tPress any key to start\n");
    changemode(1);
    getc(stdin);
    while (1) {
        while (!kbhit()) {
            changemode(1);
            if (sleeptime >= 10000) {
                sleeptime -= 80;
            }
            printf("\n\tScore: %d\tAmmo: %d\n", score, ammo);
            if (!(score++ % 10)) {
                floor1[CANVAS - (rand() % 5 + 1)] = 'X';
            }
            if (!(score % 50) && ammo <= 10) {
                ammo++;
            }
            if (isDead(floor1, current_floor, score)) {
                return 0;
            }
            if (current_floor == 1 || (current_floor == 2 && delay)) {
                printf("\n\n\t");
                display(floor2, 0, CANVAS);
                printf("\n\t");
                display(floor1, 0, PLAYERPOS);
                printf("0");
                display(floor1, PLAYERPOS + 1, CANVAS);
                printf("\n\n");
                if (delay) {
                    delay--;
                }
            } else if (current_floor == 2 && delay == 0) {
                if (jump_time++ > 4) {
                    jump_time = 0;
                    current_floor = 1;
                    delay = 2;
                }
                printf("\n\n\t");
                display(floor2, 0, PLAYERPOS);
                printf("0");
                display(floor2, PLAYERPOS + 1, CANVAS);
                printf("\n\t");
                display(floor1, 0, CANVAS);
                printf("\n\n");
            }
            if (stop) {
                printf("\n\t\t\033[31mZaWarudo!!\033[0m\n");
                getc(stdin);
                stop = false;
            }
            shiftLeft(floor1, CANVAS);
            usleep(sleeptime);
            system("clear");
        }
        if (isDead(floor1, current_floor, score)) {
            return 0;
        }
        char temp = getc(stdin);
        if (temp == 'w') {
            current_floor = 2;
        } else if (temp == ' ') {
            if (ammo) {
                floor1[PLAYERPOS + 1] = '-';
                ammo--;
            }
        } else if (temp == 'p') {
            stop = true;
        }
    }
    changemode(0);
    return 0;
}

void display(char *floor, int lowerlimit, int upperlimit) {
    for (int i = lowerlimit; i < upperlimit; i++) {
        printf("%c", floor[i]);
    }
}

void shiftLeft(char *floor, int upperlimit) {
    for (int i = 0; i < upperlimit - 1; i++) {
        if (floor[i] == '-' && floor[i + 1] == 'X') {
            floor[i] = '_';
            floor[i + 1] = '_';
        } else if (floor[i] == '-' || floor[i + 1] == '-') {
            continue;
        } else {
            floor[i] = floor[i + 1];
        }
    }
    for (int i = upperlimit - 2; i > 0; i--) {
        if (floor[i] == '-' && floor[i + 1] == 'X') {
            floor[i] = '_';
            floor[i + 1] = '_';
        } else if (floor[i] == '-') {
            floor[i + 1] = '-';
            floor[i] = '_';
        }
    }
    floor[upperlimit - 1] = '_';
}
bool isDead(char *floor, int current_floor, int score) {
    if (current_floor == 1 && floor[PLAYERPOS] == 'X') {
        system("clear");
        printf("\n\t\tScore: %d\n", score);
        printf("\n\t\tGame Over!\n\n");
        return true;
    }
    return false;
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