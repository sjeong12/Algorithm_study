#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int map[501][501];
int visit[501][501];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, M, ans = 0;

void getMaxNum(int y, int x, int cnt, int source)
{
	if (cnt == 4)
	{
		if (ans < source)
			ans = source;
		return ;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx])
			continue;
		visit[ny][nx] = 1;
		getMaxNum(ny, nx, cnt + 1, source + map[ny][nx]);
		visit[ny][nx] = 0;
	}

	if (y - 1 >= 0 && x - 1 >= 0 && y + 1 < N)//ㅓ
		ans = max(ans, (map[y][x-1] + map[y][x] + map[y-1][x] + map[y+1][x]));
	if (y - 1 >= 0 && x + 1 <= M && y + 1 < N)//ㅏ
		ans = max(ans, (map[y][x] + map[y][x+1] + map[y - 1][x] + map[y + 1][x]));
	if (x - 1 >= 0 && x + 1 < M && y + 1 < N)//ㅗ
		ans = max(ans, (map[y][x] + map[y+1][x] + map[y+1][x-1] + map[y+1][x+1]));
	if (x - 1 >= 0 && x + 1 < M && y + 1 < N)//ㅜ
		ans = max(ans, (map[y][x-1] + map[y][x] + map[y][x+1] + map[y+1][x]));
}

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	memset(visit, 0, sizeof(visit));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visit[i][j] = 1;
			getMaxNum(i, j, 1, map[i][j]);
			visit[i][j] = 0;
		}
	}
	
	cout << ans << '\n';
	return (0);
}