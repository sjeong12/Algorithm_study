#include <stdio.h>

/* 버블 정렬
int main(void)
{
    int N;
    int temp = 0;
    int arr[1000];

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < N; i++)
        printf("%d\n", arr[i]);
    
    return (0);
}
*/

//삽입 정렬
int main(void)
{
    int arr[1000];
    int N;
    int value = 0;
    int i, j;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    for (i = 1; i < N; i++)
    {
        value = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > value)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = value;
    }

    for (int i = 0; i < N; i++)
        printf("%d\n", arr[i]);
    return (0);
}