#include <stdio.h>

int T, N;
int dp[41][2];

int main(void)
{
    scanf("%d", &T);
    //0의 0과 1의 갯수
    dp[0][0] = 1;
    dp[0][1] = 0;
    //1의 0과 1의 갯수
    dp[1][0] = 0;
    dp[1][1] = 1;

    //이미 알고있는 작은 수를 토대로 큰 수를 구하는 bottom-up 방식
    for (int i = 2; i <= 40 ; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];//0의 갯수를 구하는 라인
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];//1의 갯수를 구하는 라인
    }

    for (int i = 0; i < T; i++)
    {
        scanf("%d", &N);
        printf("%d %d\n", dp[N][0], dp[N][1]);
    }

    return 0;
}