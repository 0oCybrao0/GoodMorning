#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int critical_point[100] = {0};
    int element_num = 0;
    int flag = 0;
    int min = 100;
    int max_first = 0;
    int max_last = 0;
    int path = 0;
    int change_times = 0;
    scanf("%d", &element_num);
    for (int times = 0; times < element_num; times++) {
        scanf("%d", &critical_point[times]);
    }

    for (int i = 1; i < element_num - 1; i++) {
        path++;
        if (critical_point[i] < critical_point[i + 1] && critical_point[i] < critical_point[i - 1]) {
            if (flag == 0) {
                flag = 1;
                path = 0;
                max_first = i;
                continue;
            }
            max_last = i;
            change_times = 1;
            if (path < min) {
                min = path;
            }
            path = 0;
        }
        if (critical_point[i] > critical_point[i + 1] && critical_point[i] > critical_point[i - 1]) {
            if (flag == 0) {
                flag = 1;
                path = 0;
                max_first = i;
                continue;
            }
            max_last = i;
            change_times = 1;
            if (path < min) {
                min = path;
            }
            path = 0;
        }
    }

    int max = max_last - max_first;
    if (change_times == 0) {
        printf("-1 -1\n");
    } else if (change_times == 1) {
        printf("%d %d\n", min, max);
    }
}