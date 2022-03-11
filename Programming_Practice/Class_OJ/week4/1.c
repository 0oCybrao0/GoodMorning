#include <stdio.h>
#include <stdlib.h>

int main() {
    enum { blue = 2,
           green,
           red = 10 };
    int num;
    scanf("%d", &num);
    switch (num) {
        case blue:
            printf("I like blue.\n");
            break;
        case green:
            printf("I like green.\n");
            break;
        case red:
            printf("I like red.\n");
            break;
        default:
            printf("Nope.\n");
            break;
    }
}