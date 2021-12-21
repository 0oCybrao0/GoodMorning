#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct xy {
    int x;
    int y;
} xy;

int main() {
    xy lost[1000];
    int lost_i = -1;
    int x_edge, y_edge;
    scanf("%d %d\n", &x_edge, &y_edge);
    int x, y;
    char ori;
    char direction[4] = {'N', 'E', 'S', 'W'};
    while (scanf("%d %d %c\n", &x, &y, &ori) != EOF) {
        int deg = 0;
        for (int i = 0; i < 4; i++) {
            if (ori == direction[i]) {
                deg = i * 90;
            }
        }
        char a;
        int flag_index = 0;
        while (1) {
            a = getchar();
            if (a == '\n') {
                break;
            }
            if (a == 'L') {
                deg -= 90;
                if (deg == -90) {
                    deg = 270;
                }
            } else if (a == 'R') {
                deg += 90;
                if (deg == 360) {
                    deg = 0;
                }
            } else if (a == 'F') {
                int flag = 0;
                if (deg == 0) {
                    for (int i = 0; i <= lost_i; i++) {
                        if (x == lost[i].x && y == lost[i].y) {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) {
                        y++;
                    }
                }
                if (deg == 90) {
                    for (int i = 0; i <= lost_i; i++) {
                        if (x == lost[i].x && y == lost[i].y) {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) {
                        x++;
                    }
                }
                if (deg == 180) {
                    for (int i = 0; i <= lost_i; i++) {
                        if (x == lost[i].x && y == lost[i].y) {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) {
                        y--;
                    }
                }
                if (deg == 270) {
                    for (int i = 0; i <= lost_i; i++) {
                        if (x == lost[i].x && y == lost[i].y) {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) {
                        x--;
                    }
                }
            }
            if (x < 0 || y < 0 || x > x_edge || y > y_edge) {
                if (x < 0) {
                    x++;
                }
                if (y < 0) {
                    y++;
                }
                if (x > x_edge) {
                    x--;
                }
                if (y > y_edge) {
                    y--;
                }
                flag_index = 1;
                while (getchar() != '\n')
                    ;
                break;
            }
        }
        int flag = 0;
        for (int i = 0; i <= lost_i; i++) {
            if (x == lost[i].x && y == lost[i].y) {
                flag = 1;
                break;
            }
        }
        if (flag_index == 1) {
            lost_i++;
            lost[lost_i].x = x;
            lost[lost_i].y = y;
        }
        if ((x == 0 || y == 0 || x == x_edge || y == y_edge) && flag == 0) {
            printf("%d %d %c lost\n", x, y, direction[deg / 90]);
        } else {
            printf("%d %d %c\n", x, y, direction[deg / 90]);
        }
    }
}