#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int square[25][25];//맵
int visited[25][25] = {0};//방문여부
vector<int> cntVec;
int m_x[4] = {0, 1, 0 ,-1};
int m_y[4] = {1, 0, -1, 0};
int N, cnt;

void DFS(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + m_x[i];//상하좌우 탐색
		int next_y = y + m_y[i];

		if (next_x >= N || next_x < 0 || next_y >= N || next_y < 0)
			continue ; //맵 범위를 넘어갔으면 다른 방향 탐색
		
		if (!visited[next_y][next_x] && square[next_y][next_x])
		{
			visited[next_y][next_x] = 1;
			cnt += 1;//단지 내 집 갯수 증가
			DFS(next_y, next_x);//다음 지역 탐색
		}
	}
}

int main(void)
{
	int result = 0;
	string str;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			visited[i][j] = 0;//모든 방문여부를 0으로 초기화
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
			if (square[i][j] && !visited[i][j])
			{
				visited[i][j] = 1;
				cnt = 1;//시작점도 갯수에 포함하므로 1로 초기화
				DFS(i, j);
				cntVec.push_back(cnt);//단지내의 집 갯수를 vector에 저장
				result++;//탐색을 다했으므로 단지 수 증가
			}
		}
	}

	sort(cntVec.begin(), cntVec.end());
	cout << result << "\n";//총 단지 수 출력

	for (int i = 0; i < cntVec.size(); i++)
		cout << cntVec[i] << "\n";//단지 내 집 갯수 출력
}
