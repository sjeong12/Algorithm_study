#include <stdio.h>

int	main()
{
	//dp[num][end] = num개의 숫자로, 숫자 end를 만드는 경우의 수
	int		n, k;
	long	dp [201][201] = {0, };

	//입력 및 초기화
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= n; i++)
		dp[1][i] = 1;
	//풀이 - dp[k][n]를 찾는다
	for (int num = 2; num <= k; num++)
		for (int end = 0; end <= n; end++)
		{	//num-1개의 숫자로, end이하의 수를 만드는 모든 경우의 수를 합산
			for (int before = 0; before <= end; before++)
			{
				dp[num][end] += dp[num - 1][before];
			}
			dp[num][end] %= 1000000000;
		}
		printf("%d\n", dp[k][n]);
	return (0);
}