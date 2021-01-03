#include <stdio.h>
#include <algorithm>

using namespace std;

int	main()
{	//dp[c][r] = 해당 위치의 스티커에서 얻을 수 있는 최대 점수
	int	t, n, sticker[100001][2], dp[100001][2];

	scanf("%d", &t);
	while (t--)
	{	//입력 및 초기화
		scanf("%d", &n);
		for (int r = 0; r < 2; r++)
			for (int c = 1; c <= n; c++)
				scanf("%d", &sticker[c][r]);
		dp[0][0] = 0;
		dp[0][1] = 0;
		dp[1][0] = sticker[1][0];
		dp[1][1] = sticker[1][1];
		//두칸 이내의 대각선 방향 스티커만 참조
		//(세칸 이상의 거리는, 대각선으로 한 칸씩 이동하여 도달 가능)
		for (int c = 2; c <= n; c++)
		{
			dp[c][0] = sticker[c][0] + max(dp[c - 1][1], dp[c - 2][1]);
			dp[c][1] = sticker[c][1] + max(dp[c - 1][0], dp[c - 2][0]);
		}
		printf("%d\n", max(dp[n][0], dp[n][1]));
	}
	return (0);
}