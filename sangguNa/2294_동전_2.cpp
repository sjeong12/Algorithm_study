#include <iostream>

using namespace std;

int MIN(int a, int b)
{
	return (a < b ? a : b);
}

int main(void)
{
	int dp[10001] = {0, };
	int n, k, coin[101];

	cin >> n >> k;

	for (int i = 1; i <= k; i++)
		dp[i] = 10001;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> coin[i];
		for (int j = coin[i]; j <= k; j++)
		{
			dp[j] = MIN(dp[j], dp[j - coin[i]] + 1);
		}
	}
	if (dp[k] == 10001)
		cout << -1 << '\n';
	else
		cout << dp[k] << '\n';
	return (0);
}