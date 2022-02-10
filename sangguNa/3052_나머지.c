#include <stdio.h>

int main(void)
{
    int arr[42] = {0, };
    int temp;
    int count = 0;

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &temp);
        temp = temp % 42;
        arr[temp] += 1;
    }

    for (int i = 0; i < 42; i++)
    {
        if (arr[i] != 0)
            count++;
    }
    
    printf("%d\n", count);
}