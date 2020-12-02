#include <stdio.h>

int main(void)
{
    int a; //입력값을 저장할 변수 A
    int b; //입력값을 저장할 변수 B
    int count; //몇개의 테스트 케이스를 입력받을지 저장하는 변수 count

    scanf("%d", &count); //사용자로부터 테스트 케이스의 개수를 입력받음

    //입력받은 테스트 케이스만큼 A + B를 출력함.
    //이때, 0 < A, B < 10 를 만족하지 않으면 조건이 맞지 않는다고 출력문을 만들었음.
    for(int i = 0; i < count; i++)
    {
        scanf("%d,%d", &a, &b);

        if((a > 0 && a < 10) && (b > 0 && b < 10))
            printf("%d\n", a + b);
    }

    return(0);
}