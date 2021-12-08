#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct frequency {
    int ascii;
    int times;
} frequency;

int compare(const void *, const void *);

int main() {
    frequency f[127] = {0};
    char str[1001] = {0};
    while (gets(str)) {
        for (int i = 32; i <= 126; i++) {
            f[i].ascii = i;
            f[i].times = 0;
        }
        int length = strlen(str);
        for (int i = 0; i < length; i++) {
            f[str[i]].times++;
        }
        qsort(f, 127, sizeof(frequency), compare);
        for (int i = 32; i <= 126; i++) {
            if (f[i].times > 0) {
                printf("%d %d\n", f[i].ascii, f[i].times);
            }
        }
        puts("");
    }
}

int compare(const void *a, const void *b) {
    if ((*(frequency *)a).times == (*(frequency *)b).times) {
        return (*(frequency *)b).ascii - (*(frequency *)a).ascii;
    }
    return (*(frequency *)a).times - (*(frequency *)b).times;
}