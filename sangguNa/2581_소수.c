#include <stdio.h>

int erato[10001] = {0, };

void eratos_init(void)
{
    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 1; j <= 10000; j++)
        {
            if (i * j <= 10000)
                erato[i * j] += 1;
            else
                break;
        }
    }
}

int main(void)
{
    int M, N;
    int sum, min, count;

    eratos_init();
    scanf("%d %d", &M, &N);
    min = 10000000;
    sum = 0;
    count = 0;
    for (int i = M; i <= N; i++)
    {
        if (erato[i] == 2)
        {
            if (i < min)
                min = i;
            sum += i;
            count++;
        }
    }
    if (count == 0)
        printf("-1\n");
    else
        printf("%d\n%d\n", sum, min);
}