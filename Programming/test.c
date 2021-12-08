#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int shell_sort(int *A, int n) {
    int span, i;
    span = n / 2;
    while (span >= 1) {
        for (i = 0; i < (n - span); i++) {
            if (A[i] > A[i + span]) {
                swap(&A[i], &A[i + span]);
            }
        }
        span = span / 2;
    }
}

int main() {
    int count, i;
    scanf("%d", &count);
    int list[count];
    printf("Numbers to be sorted: ");
    for (i = 0; i < count; i++) {
        scanf("%d", &list[i]);
        // printf("%d ", list[i]);
    }
    shell_sort(list, count);
    for (i = 0; i < count; i++) {
        printf("%d%s", list[i], i == count - 1 ? '\n' : ' ');
    }
}