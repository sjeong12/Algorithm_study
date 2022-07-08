#include <iostream>

using namespace std;

int main(void)
{
	int N;
	int dp[100001][3];
	/*
	dp[a][b] = c : a번째 줄에 b번에 사자를 배치했을 때의 경우의 수는 c
	0 : 사자를 아무데도 배치안했을 경우
	1 : 사자를 왼쪽에 배치했을 경우
	2 : 사자를 오른쪽에 배치했을 경우
	*/
	cin >> N;
	
	dp[1][0] = dp[1][1] = dp[1][2] = 1;
	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
	}

	cout << (dp[N][0] + dp[N][1] + dp[N][2]) % 9901 << '\n';
	return (0);
}