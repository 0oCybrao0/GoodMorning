#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100001];
    scanf("%s", input);
    int len = strlen(input);
    int total = 0;
    for (int i = 1; i < len; i++) {
        int count1 = 0, count2 = 0;
        int frequency1[26] = {0}, frequency2[26] = {0};
        for (int j = 0; j < i; j++) {
            frequency1[input[j] - 'a']++;
        }
        for (int j = i; j < len; j++) {
            frequency2[input[j] - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            if (frequency1[j]) {
                count1++;
            }
            if (frequency2[j]) {
                count2++;
            }
        }
        if (count1 == count2) {
            total++;
        }
    }
    printf("%d\n", total);
}