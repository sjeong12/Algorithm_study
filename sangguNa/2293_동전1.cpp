#include <iostream>
using namespace std;

int N, K;
int coin[101]; //동전의 가치
int dp[10001]; //dp[a] = b : a원을 만들 수 있는 경우의 수는 b가지다.

int main(void)
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> coin[i];

    dp[0] = 1; //0원을 만들 수 있는 경우의 수는 '아무 동전도 사용하지 않는 경우' -> 1가지, 중요

    for (int i = 1; i <= N; i++) //n가지 코인 만큼 반복
    {
        for (int j = coin[i]; j <= K; j++) //1번째 코인부터 시작
        {
            /*
                0원에서 3원을 이용해 3원으로 만드는 경우:dp[3] = dp[3] + dp[0]
                1원에서 2원을 이용해 3원으로 만드는 경우:dp[3] = dp[3] + dp[1], 왜냐하면 기존 1원을 가지고 있어야 2원을 가지고
                 3원을 만들기 때문
                즉, 현재 x원을 가지고 있다면, 이 동전을 이용해 y원을 만든다면->dp[y] = dp[y] + dp[y - x]
                근데 0원에서 3원을 만들때 식이 dp[3] = dp[3] + dp[0]인데, dp[0] = 0 이면 dp[3] = 0이 되버린다.
                그래서 dp[0] = 1로 초기화한 것이다.
            */
            dp[j] = dp[j] + dp[j - coin[i]];
        }
    }

    cout << dp[K] << endl;

    return (0);
}