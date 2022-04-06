#include <stdio.h>
#include <string.h>

int main() {
    char *input = malloc(sizeof(char) * 100);
    scanf("%s", input);
    int op1 = 0, op2 = 0, len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (input[i] == '(') {
            op1++;
            op2++;
        } else if (input[i] == ')') {
            op1--;
            op2--;
        } else if (input[i] == '*') {
            op1--;
            op2++;
        }
        if (op1 < 0) {
            op1 = 0;
        }
        if (op2 < 0) {
            printf("false\n");
            return 0;
        }
    }
    if (op1 == 0) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}