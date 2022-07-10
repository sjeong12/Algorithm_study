#include <iostream>
#include <cmath>

using namespace std;

int N, min_h, max_h, cnt, answer;
int map[101][101];
bool check[101][101];
int dx[] = {1, 0 , -1, 0};
int dy[] = {0, 1, 0, -1};

void	DFS(int y, int x, int h)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
			continue;
		if (map[ny][nx] <= h || check[ny][nx])
			continue;
		
		check[ny][nx] = true;
		DFS(ny, nx, h);
	}
}

void	check_reset(void)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			check[i][j] = false;
}

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	max_h = -1, min_h = 101;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			min_h = min(min_h, map[i][j]);
			max_h = max(max_h, map[i][j]);
		}
	}

	answer = 1;
	for (int i = min_h; i <= max_h; i++)
	{
		cnt = 0;
		check_reset();
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (map[j][k] > i && check[j][k] == false)
				{
					check[j][k] = true;
					cnt++;
					DFS(j, k, i);
				}
			}
		}

		answer = max(answer, cnt);
	}
	cout << answer << '\n';
	return (0);
}