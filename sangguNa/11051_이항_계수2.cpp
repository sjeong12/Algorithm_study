#include <iostream>
#include <algorithm>

using namespace std;

long long dp[1001][1001];

void binominal(long long N, long long K)
{
	long long i, j;

	for (i = 0; i <= N; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				dp[i][j] = 1;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}
}

int main(void)
{
	long long N, K;

	cin >> N >> K;
	binominal(N, K);
	cout << dp[N][K] << '\n';
	return (0);
}