#include <stdio.h>
#include <string.h>

int main(void)
{
    int T;
    char arr[80];
    int temp, sum;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", &arr);
        temp = 0;
        sum = 0;

        for (int i = 0; i < strlen(arr); i++)
        {
            if (arr[i] == 'O')
            {
                 temp += 1;
                 sum += temp;
            }
            else if (arr[i] == 'X')
                temp = 0;
        }
        printf("%d\n", sum);
    }
    return (0);
}