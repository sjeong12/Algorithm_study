#include <iostream>
#include <algorithm>

#define range 1025

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int arr[range][range];
	int dp[range][range];
	int n, m, ans;
	int input;

	int x1, y1, x2, y2;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> input;
			if (i == 1 && j == 1)
				dp[i][j] = input;
			else if (i == 1)
				dp[i][j] = input + dp[i][j - 1];
			else if (j == 1)
				dp[i][j] = input + dp[i - 1][j];
			else
				dp[i][j] = input + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		ans = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
		cout << ans << '\n'; 
	}
	return (0);
}