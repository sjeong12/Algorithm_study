#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define RED		2
#define	BLUE	3

using namespace std;

vector<int> vec[20001];
int visited[20001];
int V, E;//V:정점의 개수, E:간선의 개수

void DFS(int start)
{
	//탐색 안한 점이면 RED로 설정
	if (visited[start] == 0)
		visited[start] = RED;
	
	//연결된 점들 방문
	for (int i = 0; i < vec[start].size(); i++)
	{
		int idx = vec[start][i];
		if (visited[idx] == 0)//방문 안한 점이면
		{
			if (visited[start] == RED)//색칠하기
				visited[idx] = BLUE;
			else if (visited[start] == BLUE)
				visited[idx] = RED;
			DFS(idx);
		}
	}
}

//이분 그래프 판별
int check(void)
{
	for (int i = 1; i <= V; i++)//인접한 노드와 색이 같으면 이분 그래프가 아님
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			int idx = vec[i][j];
			if (visited[i] == visited[idx])
				return (false);
		}
	}
	return (true);
}

int main(void)
{
	int K;
	int u, v;
	
	cin >> K;
	while (K--)
	{
		cin >> V >> E;
		for (int i = 0; i < E; i++)
		{
			cin >> u >> v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}

		//전체 방문을 위해 1부터 전부 방문
		for (int i = 1; i <= V; i++)
		{
			if (visited[i] == 0)
				DFS(i);
		}

		//이분 그래프 여부 확인
		if (check() == 0)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
		
		memset(vec, 0, sizeof(vec));
		memset(visited, 0, sizeof(visited));
	}

	return (0);
}