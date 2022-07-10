#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char str[1000000];
    int count, len, i;

    scanf("%[^\n]s", &str);//%[^\n]s : 개행이 나오기 전까지는 공백도 포함해서 문자열 입력받기
    len = strlen(str);
    count = 0;
    i = 0;
    while (i < len)
    {
        if (str[i] == ' ')
            i++;
        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            while(str[i] != ' ' && str[i] != '\0')
                i++;
            count++;
        }
    }
    printf("%d\n", count);
}