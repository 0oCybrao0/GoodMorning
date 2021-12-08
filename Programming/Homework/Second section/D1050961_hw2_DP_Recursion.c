#include <stdio.h>

int climbStairs(int);
int value[46] = {0};

int main() {
    int n = 0;
    scanf("%d", &n);
    printf("%ld\n", climbStairs(n));
}

int climbStairs(int n) {
    if (n <= 2)
        return n;
    if (!value[n - 1])  // if the value in the previous one doesn't exist , make it exist
        value[n - 1] = climbStairs(n - 1) + climbStairs(n - 2);
    return value[n - 1];
}