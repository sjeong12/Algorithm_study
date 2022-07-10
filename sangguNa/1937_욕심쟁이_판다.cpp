#include <iostream>

#define MAX		500

using namespace std;

int N, answer;
int Map[MAX][MAX];
int DP[MAX][MAX];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int Bigger(int a, int b)
{
	return (a > b ? a : b);
}

int move(int y, int x)
{
	if (DP[y][x] != 0)//이미 방문한 곳이면 return
		return (DP[y][x]);
	DP[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= 0 && ny < N && nx >= 0 && nx < N)
		{
			if (Map[y][x] < Map[ny][nx])
				DP[y][x] = Bigger(DP[y][x], move(ny, nx) + 1);
		}
	}

	return (DP[y][x]);
}

int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> Map[i][j];
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			answer = Bigger(answer, move(i, j));
	
	cout << answer << '\n';
	return (0);
}