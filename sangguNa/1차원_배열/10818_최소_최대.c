#include <stdio.h>

int main(void)
{
    int N;
    int arr[1000001];
    int min_num = 1000000;
    int max_num = -1000000;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    
    for (int i = 0; i < N; i++)
    {
        if (arr[i] < min_num)
            min_num = arr[i];
        if (arr[i] > max_num)
            max_num = arr[i];
    }

    printf("%d %d\n", min_num, max_num);
}