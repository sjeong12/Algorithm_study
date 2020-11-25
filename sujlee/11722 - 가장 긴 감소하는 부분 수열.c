#include <stdio.h>

int	main()
{
	int	n, a[1000], dp[1000];	//dp[a] = b; a번째 인덱스까지의 부분수열 최대 길이는 b
	int	now, before, max_size = 1;	//now = 현재 인덱스, before = 이전 인덱스

	//입력
	scanf("%d", &n);
	for (now = 0; now < n; now++)
		scanf("%d", &a[now]);
	//풀이
	dp[0] = 1;
	for (now = 1; now < n; now++)
	{
		dp[now] = 1;
		for (before = now - 1; before >= 0; before--) //now 이전 인덱스들을 역순으로 조회
			if (a[before] > a[now])
			{
				if (dp[before] + 1 > dp[now])	//now 인덱스까지의 부분수열 최대 길이 갱신
					dp[now] = dp[before] + 1;
				if (dp[now] > max_size)			//전체의 부분수열 최대 길이 갱신
					max_size = dp[now]; 
			}
	}
	//출력
	printf("%d", max_size);
	return (0);
}