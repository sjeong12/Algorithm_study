#include <stdio.h>

int main(void)
{
    int N;
    int sum, temp;

    scanf("%d", &N);
    for (int i = 1; i < N; i++)
    {
        temp = i;//자릿수를 더하기 위한 변수
        sum = i;//자기 자신을 먼저 더한 상태

        while (temp > 0)
        {
            sum += temp % 10;//1의 자리부터 한 자리씩 더해줌
            temp /= 10;//다음 자리를 더하기 위해 /10
        }

        if (sum == N)//입력된 N과 같은 sum이 나왔다면 생성자
        {
            printf("%d\n", i);
            N = 0;
            break;
        }
    }
    if (N != 0)//생성자가 없을경우 0 출력
        printf("0\n");
    return (0);
}