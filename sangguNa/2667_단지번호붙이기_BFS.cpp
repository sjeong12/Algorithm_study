#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int square[25][25];
int visited[25][25];
int danji[25 * 25 + 1];
int m_x[4] = {0, 1, 0 ,-1};
int m_y[4] = {1, 0, -1, 0};
int N, cnt;
int idx = 0;

void BFS(int y, int x)
{
	queue<pair<int, int >> q;//1.큐 선언
	q.push(make_pair(y, x));//2.좌표 푸쉬
	visited[y][x] = 1;//3.방문했다고 표시
	cnt++;//집이 있으므로 cnt 증가

	while (!q.empty())
	{
		y = q.front().first;//4.큐의 좌표를 가져온 뒤 pop();
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + m_x[i];
			int ny = y + m_y[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			//범위내에 있고, 다음 탐색지에 집이 존재하고, 방문하지 않은 곳이면
			if (square[ny][nx] && !visited[ny][nx])
			{
				q.push(make_pair(ny, nx));//그 좌표를 큐에 저장
				visited[ny][nx] = 1;//방문했다 표시
				cnt++;//cnt 증가, 이 과정을 큐가 빌 때까지 반복
			}
		}
	}
	
}

int main(void)
{
	string str;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			visited[i][j] = 0;
			if (str[j] == '1')
				square[i][j] = 1;
			else
				square[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (square[i][j] && !visited[i][j])//집이 있고 방문하지않은 곳이면
			{
				BFS(i, j);//현재 좌표부터 bfs 실행
				danji[idx++] = cnt;//bfs 내부에서 계산한 cnt 저장 및 초기화
				cnt = 0;
			}
		}
	}

	sort(danji, danji + idx);
	cout << idx << "\n";//단지 갯수 출력
	for (int i = 0; i < idx; i++)
		cout << danji[i] << "\n";//단지내 집 갯수 출력
}