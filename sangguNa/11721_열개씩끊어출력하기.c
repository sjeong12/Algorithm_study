#include <stdio.h>
#include <string.h> //strlen을 사용하기위해 추가

int main(void)
{
    char c[100];

    scanf("%s", &c); //문자열이기 때문에 %s 사용

    for(int i = 0; i < strlen(c); i++)
    {
        printf("%c", c[i]);
        if(i % 10 == 9) //10번째 글자(배열에서는 9번째)라면
            printf("\n"); //줄바꿈 출력
    }
    
    return(0);
}