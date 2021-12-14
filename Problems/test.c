#include <stdio.h>
#include <stdlib.h>

void cycle_length(int, int, int *);
void compare(int, int, int *);

int main()
{
    int min = 0;
    int max = 0;
    while(scanf("%d%d", &min, &max) != 0)
    {
        if(max < min)
        {
            int temp = max;
            max = min;
            min = temp;
        }
        printf("%d %d ", min, max);
        int num = max - min + 1;
        int *count = (int *)calloc(num, sizeof(int));
        cycle_length(min, max, count);
        compare(min, max, count);
    }
}

void cycle_length(int min, int max, int *count)
{
    int times = 0;
    for (int i = min; i <= max; i++)
    {
        int n = i;
        times = 0;
        while(n != 1)
        {
            if(n % 2 == 0)
            {
                times++;
                n /= 2;
            }
            else
            {
                times++;
                n = n * 3 + 1;
            }
        }
        times++;
        count[i - min] = times;
    }
}

void compare (int min, int max, int *count)
{
    int M = count[0];
    for(int i = 0; i <= max - min; i++)
    {
        if(M < count[i])
        {
            M = count[i];
        }
    }
    printf("%d\n", M);
}