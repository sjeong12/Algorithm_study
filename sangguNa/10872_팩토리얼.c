#include <stdio.h>

int facto(int n)
{
    if (n == 1)
        return (1);
    if (n == 0)
        return (1);
    return (n * facto(n - 1));
}

int main(void)
{
    int N, result;

    scanf("%d", &N);
    result = facto(N);
    printf("%d\n", result);
}