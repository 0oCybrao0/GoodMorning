#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    enum { sunday = 1,
           monday,
           tuesday,
           wednesday,
           thursday,
           friday,
           saturday };
    int num = 0;
    scanf("%d", &num);
    switch (num) {
        case sunday:
            printf("Today is sunday");
            break;
        case monday:
            printf("Today is monday");
            break;
        case tuesday:
            printf("Today is tuesday");
            break;
        case wednesday:
            printf("Today is wednesday");
            break;
        case thursday:
            printf("Today is thursday");
            break;
        case friday:
            printf("Today is friday");
            break;
        case saturday:
            printf("Today is saturday");
            break;
        default:
            printf("Doesn't have this day");
            break;
    }
}