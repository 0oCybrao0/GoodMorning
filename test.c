#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    while (1) {
        srand(time(NULL));
        printf("%d\n", rand());
    }
}