#include <stdio.h>
#include <algorithm>

using namespace std;

int	main()
{
	int	n, m;
	int	r, c, sum; //행,열,총 사탕개수
	int	map[1001][1001];

	//입력
	scanf("%d %d", &n, &m);
	for (r = 1; r <= n; r++)
		for (c = 1; c <= m; c++)
			scanf("%d", &map[r][c]);
	//풀이 - dp 방식.
	//왼쪽이나 위쪽으로 돌아갈일이 없기 때문에, dp배열을 따로 선언하지 않고, map에 누적된 사탕개수를 덮어씌운다
	for (r = 1; r <= n; r++)
		for (c = 1; c <= m; c++)
		{
			sum = max(map[r-1][c], max(map[r][c - 1], map[r - 1][c - 1]));
			map[r][c] += sum;
		}
	printf("%d\n", map[n][m]);
	return (0);
}

/*
int	n, m, max, map[1000][1000];

//완전 탐색 방식으로 sum의 max값을 찾는다
//r = 행, c = 열, sum = 총 사탕 개수
void	move(int r, int c, int sum)
{
	if (r + 1 > n || c + 1 > m)
		return ;
	if (r + 1 == n && c + 1 == m)
	{
		if (sum + map[r][c] > max)
			max = sum + map[r][c];
		return ;
	}
	move(r + 1, c, sum + map[r][c]);
	move(r, c + 1, sum + map[r][c]);
	move(r + 1, c + 1, sum + map[r][c]);
	return ;
}

int		main()
{
	int	r, c; //행,열

	scanf("%d %d", &n, &m);
	for (r = 0; r < n; r++)
		for (c = 0; c < m; c++)
			scanf("%d", &map[r][c]);
	move(0, 0, 0);
	printf("%d\n", max);
	return (0);
}
*/