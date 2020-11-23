#include <stdio.h>

int main(void)
{
    int a; //더하고자하는 수를 입력받아 저장할 변수 a, b
    int b;
    int t; //입력받을 테스트 케이스의 갯수를 저장할 변수 t

    scanf("%d", &t); //테스트 케이스를 입력받음

    //테스트 케이스만큼 반복문을 수행
    for(int i = 0; i < t; i++)
    {
        scanf("%d %d", &a, &b); //두 인수 a, b를 입력받음

        if((a > 0 && a < 10) && (b > 0 && b < 10)) //0 < a, b < 10이면 덧셈을 수행함
            printf("Case #%d: %d\n", i + 1, a + b); //Case # 을 출력
        else //그게 아니라면 조건에 충족하지 않는다고 오류문을 출력함.
            printf("not enought condition\n");
    }

    return(0);
}