#include <stdio.h>

int main() {
    int points[100] = {0};
    int critical_point[100] = {0};
    int times = 0;
    scanf("%d", &times);

    for (int i = 0; i < times; i++) {
        scanf("%d", &points[i]);
    }
    for (int i = 1; i < times - 1; i++) {
        if (points[i] < points[i - 1] && points[i] < points[i + 1]) {
            critical_point[i] = 1;  // min
        }
        if (points[i] > points[i - 1] && points[i] > points[i + 1]) {
            critical_point[i] = 1;  // max
        }
    }
    int sum = 0;
    for (int i = 0; i < times; i++) {
        if (critical_point[i]) {
            sum++;
        }
    }
    if (sum <= 1) {
        printf("-1 -1\n");
        return 0;
    }
    int min = 100;
    int max = 0;
    for (int i = 0; i < times; i++) {
        if (critical_point[i]) {
            int distance = 0;
            for (int j = i + 1; j < times; j++) {
                if (critical_point[j]) {
                    distance = j - i;
                    if (distance < min) {
                        min = distance;
                    }
                    break;
                }
            }
        }
    }
    for (int i = 0; i < times; i++) {
        if (critical_point[i]) {
            for (int j = times - 1; j > i; j--) {
                if (critical_point[j]) {
                    max = j - i;
                    break;
                }
            }
            break;
        }
    }
    printf("%d %d\n", min, max);
}