#include <stdio.h>

int	main()
{
	int	n, tile[31];

	//입력 및 초기화 - 길이가 1인 타일도 있으므로, [0]을 초기화해야 중복 제거시 오류 없음
	scanf("%d", &n);
	tile[0] = 1;
	tile[1] = 1;
	tile[2] = 3;
	//풀이 - 중복을 포함한 타일 코드 개수 구하기
	for (int i = 3; i <= n; i++)
		tile[i] = tile[i - 1] + tile[i - 2] * 2;
	//중복 제거 - 좌우 대칭은 중복이 없으므로, 좌우 비대칭인 코드만 2로 나눈다
	//dp[n] == 좌우 비대칭 + 좌우 대칭이다
	//따라서, (dp[n] + 좌우 대칭) / 2 = (좌우 비대칭 + 대칭 + 대칭) / 2
	//							= 좌우 비대칭 / 2 + 대칭
	if (n % 2 == 1)
		printf("%d", (tile[n] + tile[n / 2]) / 2);
	else
		printf("%d", (tile[n] + tile[n / 2] + tile[n / 2 - 1] * 2) / 2);
	return (0);
}