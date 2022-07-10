#include <stdio.h>

int N;
int dp[1000001];

int Min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

/*
	기본적으로 주어진 수가 N일때, '(N - 1)의 최소 가짓수 + 1' 의 가짓수를 가진다 가정
	N % 3 == 0 일때 '(N / 3)의 최소 가짓수 + 1'
	N % 2 == 0 일때 '(N / 2)의 최소 가짓수 + 1' 일때,
	-1 했을때의 가짓수와 나눴을 때의 가짓수를 비교해 작은 수를 저장하기
*/
void solve(void)
{
	int temp;

	dp[0] = dp[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0)
		{
			temp = dp[i / 3] + 1;
			dp[i] = Min(dp[i], temp);
		}
		if (i % 2 == 0)
		{
			temp = dp[i / 2] + 1;
			dp[i] = Min(dp[i], temp);
		}
	}
}

int main(void)
{
	scanf("%d", &N);

	solve();
	printf("%d\n", dp[N]);
}