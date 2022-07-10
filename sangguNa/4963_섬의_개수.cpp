#include <iostream>

using namespace std;

int w, h;
int map[50][50];
bool check[50][50];
int dx[] = {0, 0, 1, -1,-1, -1, 1, 1};
int dy[] = {1, -1, 0, 0,-1, 1, -1, 1};

void	DFS(int y, int x)
{
	check[y][x] = true;

	for (int i = 0; i < 8; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= h || nx >= w)
			continue;
		if (map[ny][nx] == 1 && check[ny][nx] == false)
			DFS(ny, nx);
	}
}

void	reset(void)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			map[i][j] = 0;
			check[i][j] = false;
		}
	}
}

int main(void)
{
	while (true)
	{
		reset();

		cin >> w >> h;

		if (w == 0 && h == 0)
			break;
		
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> map[i][j];
		
		int cnt = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1 && check[i][j] == false)
				{
					DFS(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return (0);
}