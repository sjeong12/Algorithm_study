#include <stdio.h>

int main(void)
{
    //int형 변수 a,b 생성
    int a;
    int b;

    //a, b에 입력받은 값 저장하고 a+b 출력
    scanf("%d", &a);
    scanf("%d", &b);
    //문제의 조건에서 0 < a, b < 10 이라는 조건이 있었으므로 if문 사용
    if((a > 0 && a < 10) && (b > 0 && b < 10))
        printf("%d", a+b);
    else
        printf("fail to meet the conditions.\n");
    
}