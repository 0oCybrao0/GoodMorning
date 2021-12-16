#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char num[16] = {0};
    int case_count = 0;
    const char bangla[][6] = {"kuti", "lakh", "hajar", "shata"};
    while (scanf("%s", num) != EOF) {
        int length = strlen(num);
        int output = 0;
        if(length >= 15){
            output = num[0] - '0';
            printf("%d %s ", output, bangla[1]);
            length = 13;
        }
        if(length >= 13){
            output = num[0] - '0';
            printf("%d %s ", output, bangla[1]);
            length = 13;
        }
    }
}