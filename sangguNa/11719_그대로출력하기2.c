#include <stdio.h>

int main()
{
    char str;
    
    while (scanf("%c", &str) != EOF) //만약 입력된 문자열에 EOF(윈도우 단축기 ctrl + z)가 있으면 중단, 아니면 계속 진행
    {
        printf("%c", str); //입력받은 문자열을 출력, 여러개을 문자열을 입력해도 잘 출력됨
    }
    return (0);
}