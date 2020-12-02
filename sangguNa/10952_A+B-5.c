#include <stdio.h>

int main(void)
{
    int a; //사용자로부터 입력받은 값을 저장할 변수 a, b 생성
    int b;

    while(1) //마지막에 0, 0이 입력될 때까지 입력을 계속 받음
    {
        scanf("%d %d", &a, &b);
        
        if(a == 0 && b == 0) //만약 0, 0 을 입력받으면 프로그램을 종료함
            return (0);
        else if((a > 0 && a < 10) && (b > 0 && b < 10)) //0 < a, b < 10이면 덧셈을 수행함
            printf("%d\n", a + b);
    }
    return (0);
}