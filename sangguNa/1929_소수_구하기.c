#include <stdio.h>
#include <math.h>

bool prime_arr[1000001];

void erato_init(int N)
{
    int sqrt_value;

    prime_arr[0] = true;
    prime_arr[1] = true;

    for (int i = 2; i <= N; i++)
    {
        if (prime_arr[i])
            continue;
        for (int j = 2 * i; j <= N; j += i)
            prime_arr[j] = true;
    }
}

int main(void)
{
    int M, N;

    scanf("%d %d", &M, &N);
    erato_init(N);
    for (int i = M; i <= N; i++)
    {
        if (!prime_arr[i])
            printf("%d\n", i);
    }
    return (0);
}