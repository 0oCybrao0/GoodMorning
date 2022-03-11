#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int m, n;
    enum { John = 1,
           Teresa = 10,
           Sharon = 32,
           Bill = 40,
           Tom = 50 };
    char name[5][10] = {"John", "Teresa", "Sharon", "Bill", "Tom"};
    scanf("%d %d", &m, &n);
    if (m < n) {
        int temp = m;
        m = n;
        n = temp;
    }
    if ((m != John && m != Teresa && m != Sharon && m != Bill && m != Tom) || (n != John && n != Teresa && n != Sharon && n != Bill && n != Tom)) {
        printf("Doesn't find");
        return 0;
    }
    switch (m) {
        case John:
            printf("%s > ", name[0]);
            break;
        case Teresa:
            printf("%s > ", name[1]);
            break;
        case Sharon:
            printf("%s > ", name[2]);
            break;
        case Bill:
            printf("%s > ", name[3]);
            break;
        case Tom:
            printf("%s > ", name[4]);
            break;
        default:
            break;
    }
    switch (n) {
        case John:
            printf("%s", name[0]);
            break;
        case Teresa:
            printf("%s", name[1]);
            break;
        case Sharon:
            printf("%s", name[2]);
            break;
        case Bill:
            printf("%s", name[3]);
            break;
        case Tom:
            printf("%s", name[4]);
            break;
        default:
            break;
    }
    return 0;
}