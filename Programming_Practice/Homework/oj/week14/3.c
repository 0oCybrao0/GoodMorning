#include <stdio.h>
#include <string.h>

int main() {
    char input1[1001] = {0};
    char input2[1001] = {0};
    gets(input1);
    gets(input2);
    int len1 = strlen(input1);
    int len2 = strlen(input2);
    int max_len = ((len1 > len2) ? len1 : len2) + 1;
    char sum[1002] = {0};
    for (int i = len1 - 1; i >= 0; i--) {
        sum[max_len + i - len1] += input1[i] - '0';
    }
    for (int i = len2 - 1; i >= 0; i--) {
        sum[max_len + i - len2] += input2[i] - '0';
    }
    for (int i = max_len - 1; i >= 0; i--) {
        if (sum[i] >= 2) {
            sum[i - 1]++;
            sum[i] -= 2;
        }
        sum[i] += '0';
    }
    for (int i = 0; i < max_len; i++) {
        if (i == 0 && sum[i] == '0') {
            continue;
        }
        printf("%c", sum[i]);
    }
    puts("");
}