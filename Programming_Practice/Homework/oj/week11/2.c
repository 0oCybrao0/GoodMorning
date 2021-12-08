    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    typedef struct birthday {
        int year;
        int month;
        int day;
        char *name[20];
    } birthday;

    int compare(const void *, const void *);

    int main() {
        birthday birthday_[1000];
        int times = 0;
        scanf("%d", &times);
        for (int i = 0; i < times; i++) {
            int year, month, day;
            scanf("%d%d%d", &birthday_[i].year, &birthday_[i].month, &birthday_[i].day);
            scanf("%s", birthday_[i].name);
        }
        qsort(birthday_, times, sizeof(birthday), compare);
        for (int i = 0; i < times; i++) {
            printf("%d %d %d  %s\n", birthday_[i].year, birthday_[i].month, birthday_[i].day, birthday_[i].name);
        }
    }

    int compare(const void *a, const void *b) {
        birthday a_ = *(birthday *)a;
        birthday b_ = *(birthday *)b;
        if (a_.year == b_.year) {
            if (a_.month == b_.month) {
                if (a_.day == b_.day) {
                    return strcmp(a_.name, b_.name);
                }
                return a_.month - b_.month;
            }
            return a_.month - b_.month;
        }
        return a_.year - b_.year;
    }