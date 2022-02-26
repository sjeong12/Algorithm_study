#include <stdio.h>

int erato_arr[1001] = {0, };

void erato(void)
{
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            if (i * j <= 1000)
                erato_arr[i * j] += 1;
            else
                break;
        }
    }
}

int main(void)
{
    int N, input;
    int count = 0;

    erato();
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &input);
        if (erato_arr[input] == 2)
            count++;
    }
    printf("%d\n", count);
}