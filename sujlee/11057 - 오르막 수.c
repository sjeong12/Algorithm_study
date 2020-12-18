#include <stdio.h>

int	main()
{
	int	n, res, dp[1001][10];	//dp[n][x] = 길이가 n이며, 끝자리 숫자가 x일 때, 경우의 수

	//입력과 초기화
	scanf("%d", &n);
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	//길이가 2인 수열부터 n인 수열까지 생성
	for (int len = 2; len <= n; len++)
	{	//생성하고자하는 수열의 마지막 숫자, end(0~9)에 따라 경우의 수를 구함
		for (int end = 0; end < 10; end++)
		{
			dp[len][end] = 0;
			//길이가 1 작은 이전 수열 중, 끝자리가 end보다 작은것들만 더하면 오르막 수이다
			for (int end_before = end; end_before >= 0; end_before--)
			{
				dp[len][end] += dp[len - 1][end_before];
				dp[len][end] %= 10007;
			}
		}
	}
	res = 0;
	for (int i = 0; i < 10; i++)	//길이가 n인 수열의 모든 경우의 수를 합산
		res += dp[n][i];
	printf("%d", res % 10007);
	return (0);
}