#include <stdio.h>

void swap(int *, int *);
int main(void) {
    int a = 2;
    int b = 3;
    printf("%p\n", a);
    printf("before swap a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("after swap a = %d, b = %d\n", a, b);
}

void swap(int *a, int *b) {
    int *temp = a;
    a = b;
    b = *temp;
    printf("%p\n", b);
    printf("%p\n", &b);
}