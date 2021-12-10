#include <stdio.h>
#include <string.h>

int main() {
    char value[1001] = {0};
    while (scanf("%s", value) && value[0] != '0') {
        int sum = 0, digit = strlen(value);
        for (int i = 0; i < digit; i++) sum += (i % 2) ? (value[i] - 48) : -(value[i] - 48);
        printf("%s%s%s\n", value, " is ", (sum % 11) ? "not a multiple of 11." : "a multiple of 11.");
    }
}