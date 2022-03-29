#include <iostream>

using namespace std;

int main(void)
{
	int num[100000];
	int dp[100000];
	int N;
	int answer;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	answer = num[0];
	for (int i = 0; i < N; i++)
	{
		dp[i] = num[i];
		if (i == 0)
			continue;
		if (dp[i] < dp[i - 1] + num[i])//dp[i] 보다 이전까지 수 합 + 현재 수 가 더 크면
			dp[i] = dp[i - 1] + num[i];//dp[i] 갱신
		if (dp[i] > answer)
			answer = dp[i];
	}

	cout << answer << endl;
}