#include <stdio.h>
#define MOD 1000000000

int N;
int dp[101][10] = {};//[자릿수의 개수][0 ~ 9]를 의미
int sum;

int main(void)
{
    scanf("%d", &N);

    sum = 0;
    for (int i = 1; i < 10; i++)//1의 자릿수에선 1가지밖에 없으므로 전부 1 저장
        dp[1][i] = 1;
    
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)//끝자리가 0이면 앞자리엔 1밖에 못옴 
                dp[i][0] = dp[i - 1][1] % MOD;
            else if (j == 9)//끝자리가 9이면 앞자리엔 8밖에 못옴
                dp[i][9] = dp[i - 1][8] % MOD;
            else//그 외의 경우
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
    }

    for (int i = 0; i < 10; i++)
        sum = (sum + dp[N][i]) % MOD;
    printf("%d\n", sum);
}