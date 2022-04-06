#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#define CANVAS 50

void display(char floor[], int lowerlimit, int upperlimit) {
    int i = lowerlimit;
    for (; i < upperlimit; i++) {
        printf("%c", floor[i]);
    }
}
void shiftLeft(char floor[]) {
    int i;
    for (i = 0; i < CANVAS - 1; i++) {
        floor[i] = floor[i + 1];
    }
    floor[CANVAS - 1] = '_';
}
void insertBarrier(char *floor, int n) {
    int r = rand() % n;
    floor[CANVAS - r - 1] = 'X';
}
int isDead(int currentfloor, int playerpos, char floor1[]) {
    if (currentfloor == 1) {
        if (floor1[playerpos] == 'X') {
            printf("\t\tGAME OVER\n");
            printf("\t\tYOU DIED!\n");
            printf("If you want to restart,press 'y'\n");
            printf("If no,press'n'\n");
            if (getch() == 'y') {
                return 1;
            } else {
                printf("ByeBye");
                exit(0);
            }
        }
    }
    return 0;
}
int main() {
    int i;
    int playerpos = 6;
    int runtime;
    int currentfloor = 1;
    int score = 0;
    char floor1[CANVAS], floor2[CANVAS];
    srand(time(0));

    for (i = 0; i < CANVAS; i++) {
        floor1[i] = '_';
        floor2[i] = ' ';
    }
    floor1[CANVAS - 1] = 'X';
    printf("\t\tWELCOME");
    printf("\t\tpress any botton to start\n");
    if (getch()) {
        while (1) {
            if (isDead(currentfloor, playerpos, floor1) == 1) {
                playerpos = 6;
                currentfloor = 1;
                score = 0;
                char floor1[CANVAS], floor2[CANVAS];
                srand(time(0));

                for (i = 0; i < CANVAS; i++) {
                    floor1[i] = '_';
                    floor2[i] = ' ';
                }
                floor1[CANVAS - 1] = 'X';
            }
            if (kbhit()) {
                if (getch() == 32 && currentfloor == 1) {
                    currentfloor = 2;
                    runtime = 4;
                }
            }
            if (runtime > 0) {
                runtime--;
            }
            if (runtime == 0) {
                currentfloor = 1;
            }
            if (score % 10 == 2) {
                insertBarrier(floor1, 5);
            }

            if (currentfloor == 1) {
                printf("\n\n\n\t");
                display(floor2, 0, CANVAS);
                printf("\n\t");
                display(floor1, 0, playerpos);
                printf("0");
                display(floor1, playerpos + 1, CANVAS);
                printf("\n\n");
            } else if (currentfloor == 2) {
                printf("\n\n\n\t");
                display(floor2, 0, playerpos);
                printf("0");
                display(floor2, playerpos + 1, CANVAS);
                printf("\n\t");
                display(floor1, 0, CANVAS);
                printf("\n\n");
            }
            printf("SCORE:%d", score);
            Sleep(50);
            system("cls");
            shiftLeft(floor1);
            score++;
        }
        return 0;
    }
}