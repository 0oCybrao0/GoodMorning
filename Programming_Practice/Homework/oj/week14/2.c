#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define base 26
#define head ('A' - 1)

int main() {
    char input[1001] = {0};
    scanf("%s", input);
    int inputLen = strlen(input);
    int outputLen = (double)strlen(input) * log(base);
    int *output = (int *)calloc(outputLen + 1, sizeof(int));
    output[0] = input[0] - head;
    output[1] += output[0] / 10;
    output[0] %= 10;
    for (int i = 1; i < inputLen; i++) {
        for (int j = 0; j < outputLen; j++) {
            output[j] *= base;
        }
        for (int j = 0; j < outputLen; j++) {
            output[j + 1] += output[j] / 10;
            output[j] %= 10;
        }
        output[0] += input[i] - head;
        for (int j = 0; j < outputLen; j++) {
            output[j + 1] += output[j] / 10;
            output[j] %= 10;
        }
    }
    int flag = 0;
    for (int i = outputLen; i >= 0; i--) {
        if (output[i] > 0 && output[i] < 10) {
            flag = 1;
        }
        if (flag == 1) {
            printf("%d", output[i]);
        }
    }
}