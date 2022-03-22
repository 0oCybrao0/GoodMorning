#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *in;
FILE *out;
int judge(int, int);

int main() {
    int h, m;
    int times;
    in = fopen("t.in", "r");
    out = fopen("t.out", "w+");
    fscanf(in, "%d", &times);
    while (times--) {
        fscanf(in, "%d:%d", &h, &m);
        do {
            m++;
            if (m == 60) {
                m = 0;
                h++;
                if (h == 24) {
                    h = 0;
                }
            }
        } while (judge(h, m));
        fprintf(out, "%d:%d\n", h, m);
    }
}

int judge(int h, int m) {
    int len = 4;
    char *par = malloc(sizeof(char) * (len + 1));
    sprintf(par, "%d%d", h, m);
    for (int i = 0; i < len; i++) {
        if (par[i] == '0') {
            for (int j = i; j < len; j++) {
                par[j] = par[j + 1];
            }
            par[--len] = '\0';
            i--;
        }
    }
    printf("%s\n", par);
    for (int i = 0; i < len / 2; i++) {
        if (par[i] != par[len - 1 - i]) {
            return 1;
        }
    }
    return 0;
}