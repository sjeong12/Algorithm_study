#include <stdio.h>

int main(void)
{
    //c_count : 입력받을 갯수를 저장하는 변수
    int c_count;
    int a;
    int b;

    //몇개를 입력받을지 사용자에게 받음
    scanf("%d", &c_count);

    //입력받은 갯수 만큼 a와 b의 합을 출력한다. 이때, 조건에 맞지않으면 경고문을 출력한다.
    for(int i = 0; i < c_count; i++)
    {
        scanf("%d %d", &a, &b);
        if((a > 0 && a < 10) && (b > 0 && b < 10))
            printf("Case #%d: %d + %d = %d\n", i + 1, a, b, a + b);
    }
    return (0);
}