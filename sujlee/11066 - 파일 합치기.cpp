#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int	file[501], sum[501], dp[501][501];
//file = 입력된 비용
//dp[a][b] = a부터 b까지의 파일 합의 최소값
//sum[a] = a번째 까지의 file을 모두 더한 값

//sum 배열이 필요한 이유?
//ex) 3 1 2 -> dp[1][1] + dp[2][3] + sum[3] = 0 + 3 + 6 = 9;
//여기서 sum[3] = file[1] + dp[2][3] = 6과 같다
int	make_dp(int start, int end)
{
	if (dp[start][end] != 0x3f3f3f3f)
		return (dp[start][end]);
	if (start == end)
		return (dp[start][end] = 0);
	if (start + 1 == end)
		return (dp[start][end] = file[start] + file[end]);
	for (int mid = start; mid < end; mid++)	//mid를 증가시키며 모든 부분합을 구해본다
	{
		int left = make_dp(start, mid);
		int right = make_dp(mid + 1, end);
		dp[start][end] = min(dp[start][end], left + right);	//그 중 최소값을 찾는다
	}
	return (dp[start][end] += sum[end] - sum[start - 1]);
}

int	main()
{
	int t, k;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &k);
		sum[0] = 0;
		memset(dp, 0x3f, sizeof(dp));
		for (int i = 1; i <= k; i++)
		{
			scanf("%d", &file[i]);
			sum[i] = sum[i - 1] + file[i];	//sum[i] = i번째까지의 파일 합산
		}
		printf("%d\n", make_dp(1, k));
	}
	return (0);
}