#include <stdio.h>

int	main()
{
	int n, a[1000], dp[1000], max;	//dp[a] = 수열의 길이가 a일때, 최대 값 b

	//입력과 초기화
	scanf("%d", &n);
	max = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (max < a[i])
			max = a[i];
	}
	dp[0] = a[0];
	//풀이 - 길이 len 을 1부터 n까지 증가시키며 dp에 최대 합을 기록한다
	for (int len = 1; len < n; len++)
	{
		dp[len] = a[len];
		for (int i = 0; i < len; i++) //현재 최대길이인 len보다 작은 인덱스 중, 숫자가 작은 것만 체크
			if (a[len] > a[i] && dp[len] < dp[i] + a[len])	//그 중에서도 가장 큰 dp[len]을 찾는다
			{
				dp[len] = dp[i] + a[len];
				if (max < dp[len])	//전체 수열 중 가장 큰 max값을 찾는다
					max = dp[len];
			}
	}
	printf("%d", max);
	return (0);
}