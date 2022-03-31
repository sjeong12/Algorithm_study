#include <iostream>
#include <algorithm>

using namespace std;

//배낭 문제 점화식 : dp[i][j] = Max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);

int main(void)
{
	int N, K;
	int dp[101][100001];//dp[a][b] = c : a번째에서 b만큼 무게를 추가했을때의 가치 합은 c
	int W[101];
	int V[101];

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> W[i] >> V[i];
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j - W[i] >= 0)//현재 무게상한 j에서 w[i]의 무게를 뺐을 때 0보다 크면(= 여유로운가)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			else//안그러면 한도를 초과하기 때문에 새 물건을 집어넣을 수 없음.
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][K] << "\n";
	return (0);
}