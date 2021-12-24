#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1001] = {0};
    int times = 0;
    int count = 0;
    scanf("%s", input);
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        if (input[i] == 'L') {
            count++;
        }
        if (input[i] == 'R') {
            count--;
        }
        if (!count) {
            times++;
        }
    }
    printf("%d\n", times);
}