#include <stdio.h>

int main(void)
{
    int n = 0;
    int sum = 0;
    char str[100];

    scanf("%d", &n);
    scanf("%s", &str);

    for (int i = 0; i < n; i++)
    {
        sum = sum + str[i] - '0';
    }
    printf("%d\n", sum);

    return (0);
}