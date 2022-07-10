#include <stdio.h>

int c_arr[10001] = {0, };

int main(void)
{
    int N, num;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        c_arr[num]++;
    }

    for (int i = 1; i < 10001; i++)
    {
        if (c_arr[i])
        {    
            for (int j = 0; j < c_arr[i]; j++)
                printf("%d\n", i);
        }
    }

    return (0);
}