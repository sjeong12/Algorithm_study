#include <stdio.h>

int main(void)
{
    int t; //테스트 케이스를 입력받아 저장할 변수 t
    int a; //덧셈할 숫자를 입력받아 저장할 변수 a, b
    int b;

    scanf("%d", &t);

    for(int i = 0; i < t; i++) //입력받은 테스트 케이스만큼 반복
    {
        scanf("%d %d", &a, &b);

        if((a > 0 && a < 10) && (b > 0 && b < 10)) //0 < a, b < 10이면 덧셈을 수행함
            printf("%d\n", a + b);
        else //그게 아니라면 조건에 충족하지 않는다고 오류문을 출력함.
            printf("not enought condition\n");
    }
    return (0);
}