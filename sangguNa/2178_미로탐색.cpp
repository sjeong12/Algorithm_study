#include <iostream>
#include <queue>
using namespace std;

int N, M; //세로, 가로크기
bool visited[100][100];//방문 여부
int maze[100][100];
int length[100][100];//총 거리를 저장하는 배열
int mx[4] = {0, 1, 0, -1};
int my[4] = {1, 0, -1, 0};

void BFS(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	length[y][x] = 1;
	visited[y][x] = true;

	while (!q.empty())
	{
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + mx[i];//2. 이동 가능한 다음 좌표 계산
			int next_y = y + my[i];

			if (next_x >= 0 && next_y >= 0 && next_x < M && next_y < N
			&& maze[next_y][next_x] && !visited[next_y][next_x])
			{
				length[next_y][next_x] = length[y][x] + 1;//3. 총 이동 거리 계산
				visited[next_y][next_x] = true;
				q.push(make_pair(next_y, next_x));
			}
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &maze[i][j]);//1. scanf 서식지정자 옵션으로 폭1을 줌(1개씩 받기위해)

	BFS(0, 0);
	printf("%d\n", length[N -1][M - 1]);//종점에 저장되있는 length 출력
}