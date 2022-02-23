#include <stdio.h>
#include <string.h>

int main(void)
{
    char arr[101];
    int len, total;

    scanf("%s", &arr);
    len = strlen(arr);
    total = strlen(arr);

    for (int i = 0; i < len; i++)
    {
        if (arr[i] == 'c' || arr[i] == 's' || arr[i] == 'z')
        {    
            if (arr[i + 1] == '=' || arr[i + 1] == '-')
                total--;
        }
        else if (arr[i] == 'n' || arr[i] == 'l')
        {
            if (arr[i + 1] == 'j')
                total--;
        }
        else if (arr[i] == 'd')
        {
            if (arr[i + 1] == '-')
                total--;
            else if (arr[i + 1] == 'z' && arr[i + 2] == '=')
                total--;
        }
    }
    printf("%d\n", total);
    return (0);
}