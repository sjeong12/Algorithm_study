#include <iostream>

using namespace std;

int N, K;
long long dp[201][201]; //dp[k][n] = a 의 의미 : k개 더해서 그 합이 n이 되는 경우의 수는 a개다

int main(void)
{
    cin >> N >> K;

    for (int i = 0; i <= N; i++) //1개 더해서 그 합이 n(i)가 되는 경우의 수는 자기 자신밖에 없으므로 1개, 초기화
        dp[1][i] = 1;

    for (int k = 2; k <= K; k++)
    {
        for (int n = 0; n <= N; n++)
        {
            for (int i = 0; i <= n; i++)
            {
                dp[k][n] = dp[k][n] + dp[k - 1][i];
                //ex) 2개더해서 합이 2가 되는 경우의 수는 2+0, 1+1, 0+2인데
                //(한개를 더해서 2가 나오는 경우의 수) + (한개를 더해서 0이 나오는 경우의 수) ... 를 진행하는데
                //위 과정을 0부터 N까지 진행한다 하면 점화식을 다음과 같이 구할 수있다.
                //DP[K][N] = DP[K-1][0] + DP[K-1][1] + ... + DP[K-1][N]
            }
            dp[k][n] = dp[k][n] % 1000000000;
        }
    }

    cout << dp[K][N] << endl;

    return (0);
}