#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 8

using namespace std;

int N, M;
int res_count = 0;
int arr[MAX][MAX];
int arr_copy[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
vector <pair<int, int> > vec;

int BFS(void)
{
	queue<pair<int, int> > q;
	for (int i = 0; i < vec.size(); i++)
		q.push(make_pair(vec[i].first, vec[i].second));

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;
			if (arr_copy[ny][nx] == 0)
			{
				arr_copy[ny][nx] = 2;
				q.push(make_pair(ny, nx));
			}
		}
	}
	
	int size = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (arr_copy[i][j] == 0)
				size++;
	
	res_count = max(size, res_count);
	return (res_count);
}

int wall(int cnt)
{
	if (cnt == 3)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				arr_copy[i][j] = arr[i][j];
		}
		return (BFS());
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)
			{
				arr[i][j] = 1;
				wall(cnt + 1);
				arr[i][j] = 0;
			}
		}
	}
	return (0);
}

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				vec.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)
			{
				arr[i][j] = 1;
				wall(1);
				arr[i][j] = 0;
			}
		}
	}

	cout << res_count << '\n';
	return (0);
}