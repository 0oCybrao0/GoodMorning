#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct card {
    char suits;
    int num;
} card;

int compare(const void *, const void *);

int main() {
    card remain[100];
    int n = 0;
    scanf("%d", &n);
    getchar();
    int i = 0;
    for (i = 0; i < n - 1; i++) {
        scanf("%c %d\n", &remain[i].suits, &remain[i].num);
    }
    scanf("%c %d", &remain[i].suits, &remain[i].num);
    qsort(remain, n, sizeof(card), compare);
    for (int i = 0; i < n; i++) {
        printf("%c %d\n", remain[i].suits, remain[i].num);
    }
}

int compare(const void *a_, const void *b_) {
    card a = *(card *)a_;
    card b = *(card *)b_;
    if (a.num <= 2) {
        a.num += 13;
    }
    if (b.num <= 2) {
        b.num += 13;
    }
    if (a.num == b.num) {
        return b.suits - a.suits;
    }
    return a.num - b.num;
}