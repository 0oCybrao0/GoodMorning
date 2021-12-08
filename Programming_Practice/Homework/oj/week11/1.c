#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student {
    int id;
    int score;
} student;

int compare(const void *, const void *);

int main() {
    student a[1000];
    int times = 0;
    scanf("%d", &times);
    for (int i = 0; i < times; i++) {
        while(getchar() != 'D'){}
        scanf("%d %d", &a[i].id, &a[i].score);
    }
    qsort(a, times, sizeof(student), compare);
    for (int i = 0; i < times; i++) {
        printf("D%07d %d\n", a[i].id, a[i].score);
    }
}

int compare(const void *a, const void *b) {
    return (*(student *)a).id - (*(student *)b).id;
}