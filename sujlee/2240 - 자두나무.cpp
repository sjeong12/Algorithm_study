#include <stdio.h>
#include <algorithm>

using namespace std;

int	main()
{	//dp[나무 번호][시간 초][이동 횟수] = 해당 상황에서의 최대 값을 구한다
	int t, w, fruits[1001], dp[2][1001][32], max_res = 0;

	//입력
	scanf("%d %d", &t, &w);
	for (int i = 1; i <= t; i++)
		scanf("%d", &fruits[i]);
	//풀이
	for (int time = 1; time <= t; time++)
	{	//move - 1번만큼 이동했다고 가정한다 (move == 1 : 한 번도 이동하지 않음)
		for (int move = 1; move <= w + 1; move++)	
		{
			if (fruits[time] == 1)	//1번 나무에서 떨어질 때
			{
				//자두가 1번 나무에 서있을 경우 vs 2번 나무에 서있을 경우를 구한다
				dp[0][time][move] = max(dp[0][time - 1][move] + 1, dp[1][time - 1][move - 1] + 1);
				dp[1][time][move] = max(dp[0][time - 1][move - 1], dp[1][time - 1][move]);
			}
			else					//2번 나무에서 떨어질 때
			{	//1초대에 이동을 한번도 하지 않음 -> 2번나무에서 떨어지는 것을 먹을 수 없음(1번 나무에서 시작하므로)
				if (time == 1 && move == 1)	
					continue ;
				//자두가 1번 나무에 서있을 경우 vs 2번 나무에 서있을 경우를 구한다 
				dp[0][time][move] = max(dp[0][time - 1][move], dp[1][time - 1][move - 1]);
				dp[1][time][move] = max(dp[1][time - 1][move] + 1, dp[0][time - 1][move - 1] + 1);
			}
		}
	}
	//이동 가능 횟수 이하의 모든 dp를 비교하여 최대값을 찾는다
	for (int move = 1; move <= w + 1; move++)
		max_res = max(max_res, max(dp[0][t][move], dp[1][t][move]));
	printf("%d\n", max_res);
	return (0);
}