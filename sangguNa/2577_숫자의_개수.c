#include <stdio.h>

int main(void)
{
    int A, B, C;
    int ret, mod;
    int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);

    ret = A * B * C;
    while (ret > 0)
    {
        mod = ret % 10;
        arr[mod] += 1;
        ret /= 10;
    }
    
    for (int i = 0; i < 10; i++)
        printf("%d\n", arr[i]);
    
    return (0);
}