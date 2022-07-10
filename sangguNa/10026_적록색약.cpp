#include <iostream>
#include <string>

using namespace std;

int N, cnt = 0;
char gride[101][101];
bool check[101][101] = {false, };

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int y, int x)
{
	check[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N)
			continue;
		if (!check[ny][nx] && gride[y][x] == gride[ny][nx])
			dfs(ny, nx);
	}
}

void init_check(void)
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
	for (int i = 0; i < N; i++)
	{
		cin >> gride[i];
	}

	//정상인의 경우
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!check[i][j])
			{
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << ' ';

	//적록색약의 경우
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (gride[i][j] == 'G')
				gride[i][j] = 'R';
			else
				gride[i][j] = gride[i][j];
		}
	}
	init_check();
	cnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!check[i][j])
			{
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
}