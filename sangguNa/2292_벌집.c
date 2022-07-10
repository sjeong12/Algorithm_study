#include <stdio.h>

int main()
{
    int input = 0;
    int num = 1;
    int cnt = 6;
    int room = 1;

    scanf("%d", &input);
    if (input == 1)
        printf("%d", room);
    else
    {
        while(1)
        {
            num = num + cnt;
            room += 1;
            if (input <= num)
            {
                printf("%d", room);
                break;
            }
            cnt += 6;
        }
    }
    return (0);
}