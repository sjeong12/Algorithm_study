#include <stdio.h>

/*
    A * B % M = (A % M) * (B % M) % M 이라는 공식이 있으니 참고
    A ^ 4 를 계산할 때 A를 4번 곱하는 방법도있으나
    A ^ 2을 구하고 이를 제곱하면 계산횟수가 줄어들게됨
    B가 짝수인 경우 my_pow(A, B / 2, C)를
    1이아닌 홀수인 경우 my_pow(A, B / 2, C) * A 로 계산하면됨 
*/
long long my_pow(int A, int B, int C)
{
    long long temp;
    
    if (B == 1)
        return (A);
    else
    {
        temp = my_pow(A, B / 2, C);
        if (B % 2)
            return (((temp * temp) % C * A) % C);
        else
            return ((temp * temp) % C);
    }
}

int main(void)
{
    int A, B, C;

    scanf("%d %d %d", &A, &B, &C);

    printf("%d\n", my_pow(A % C, B, C));
}