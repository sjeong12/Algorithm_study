#include <stdio.h>

int main(void)
{
    int N, cnt, title, temp;

    cnt = 0;
    title = 0;
    scanf("%d", &N);
    while (cnt != N)
    {
        title++;
        temp = title;
        while (temp != 0)
        {
            if (temp % 1000 == 666)
            {
                cnt++;
                break;
            }
            else
                temp /= 10;
        }
    }
    printf("%d\n", title);
}