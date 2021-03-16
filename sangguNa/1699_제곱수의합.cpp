#include <iostream>
using namespace std;

int N;
int dp[100001]; //dp[a]=b : 어떤 수 a를 제곱수들의 합으로 나타낼 때, 그 최소 항의 갯수는 b개이다.
/*
    기본적으로 어떤 수 a는 a개의 항을 가진다고 정의할 수 있다. 왜냐하면 1^2 * a = a이기 때문.
    또, 어떤 수는 제곱으로 이루어져 있어(1, 4, 9, 16...) 그 수의 최소 항 갯수는 1이다.(dp[1], dp[4], ... = 1)
    예를들어 8의 최소 항 갯수를 생각해보자.
    일단 8 = 1^2 + 1^2 + ... + 1^2 로 총 8개를 가질 수 있다.(dp[8] = 8)
    이를 나눠보면 (1 + 1 + ... + 1) + (1) = dp[7] + 1로도 표현할 수 있다.
    또는 (1 + 1 + 1 + 1) + (2^2) = dp[4] + 1로도 표현할 수 있다.
    
    이렇게 보면 이전 숫자 a에 1을 더한것과 같으며, 8을 N으로 생각해서 식을 구하면 다음과 같이 나타낼 수 있다.
    dp[N] = min(dp[N - 1^2] + 1, dp[N - 2^2] + 1, dp[N - 3^2] + 1, ...)
*/

int main(void)
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        dp[i] = i; //갯수 i개로 초기화
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1); //이전 항의 갯수와 비교해서 최소의 갯수라면 갱신
        }
    }
    
    cout << dp[N] << endl;

    return (0);
}