#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

int M, N;//M : 가로길이, N : 세로길이
int map[MAX][MAX];
bool visited[MAX][MAX];
int days[MAX][MAX];
int mx[4] = {0, -1, 0, 1};
int my[4] = {-1, 0, 1, 0};
queue<pair<int, int>> q;

void BFS(void)
{
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_y = y + my[i];
			int next_x = x + mx[i];
			
			if (next_x < 0 || next_x >= M || next_y < 0 || next_y >= N)
				continue ;
			if (!map[next_y][next_x] && !visited[next_y][next_x])
			{
				visited[next_y][next_x] = true;
				q.push(make_pair(next_y, next_x));
				days[next_y][next_x] = days[y][x] + 1;
			}
		}
	}
}

int main(void)
{
	cin >> M >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	
	//익은 토마토의 위치를 시작점으로 삼기 위해 찾은 후 큐에 삽입
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 1)
				q.push(make_pair(i, j));
	
	BFS();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!map[i][j] && !days[i][j])//안익은 토마토가 있고 방문하지 못한곳이면
			{
				cout << -1 << "\n";//-1 출력
				return (0);
			}
		}
	}

	int ans = -1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (days[i][j] > ans)//다 익는 데 걸린 시간 찾아서 출력
				ans = days[i][j];
	
	cout << ans << "\n";
}