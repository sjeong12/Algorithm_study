#include <stdio.h>

int main(void)
{
    int N;
    int count;
    int cycle = 0;
    int or1, or2, nr;

    scanf("%d", &N);
    if (N < 10)
        N * 10;
    
    cycle = -1;
    count = 0;
    while (N != cycle)
    {
        if (count == 0)
        {   
            or1 = N % 10;
            or2 = (N / 10) % 10;
            nr = or2 + or1;
            cycle = (or1 * 10) + (nr % 10);
        }
        else
        {
            or1 = cycle % 10;
            or2 = (cycle / 10) % 10;
            nr = or2 + or1;
            cycle = (or1 * 10) + (nr % 10);
        }
        count += 1;
    }
    printf("%d\n", count);
}