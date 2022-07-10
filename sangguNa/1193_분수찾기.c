#include <stdio.h>

int input;//몇 번째 분수인지
int d = 0;//대각선 위치
int t = 0;//대각선 안에 몇번째 변수인지

int main(void)
{
    scanf("%d", &input);
    for (; d * (d + 1) / 2 < input; d++)//몇번째 대각선에 사용자 입력값이 있는지 확인
    {}
    t = input - (d * (d - 1) / 2);
    if (d % 2 == 0)//짝수번째 대각선은 위에서 아래
        printf("%d/%d\n", t, d - t + 1);
    else//홀수번째 대각선은 아래에서 위
        printf("%d/%d\n", d - t + 1, t);
    return (0);
}