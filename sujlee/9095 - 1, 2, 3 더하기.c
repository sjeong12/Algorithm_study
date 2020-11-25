#include <stdio.h>

int	main()
{
	int	t, n;
	int dp[11], max_index;	//max_index는 입력된 n값중 가장 큰 값

	scanf("%d", &t);
	//초기화
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	max_index = 3;
	while (t-- > 0)
	{
		//입력
		scanf("%d", &n);
		//풀이 - 1,2,3만 이용하기 때문에, dp의 -1,-2,-3인덱스 값을 더한다
		//max_index보다 작은 인덱스일 경우, 이미 dp값이 계산되어 있음
		for(int i = max_index + 1; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		//출력
		printf("%d\n", dp[n]);
	}
	return (0);
}