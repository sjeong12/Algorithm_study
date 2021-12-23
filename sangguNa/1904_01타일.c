#include <stdio.h>

int N;
int arr[1000001];

int main(void)
{
    scanf("%d", &N);

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;

    for (int i = 3; i <= N; i++)
        arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
    
    printf("%d\n", arr[N]);

    return (0);
}