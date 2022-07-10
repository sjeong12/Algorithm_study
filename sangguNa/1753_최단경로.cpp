#include <iostream>
#include <queue>
#include <vector>

#define MAX 20001
#define INF 99999999

using namespace std;

int V, E, start;
int dist[MAX];
vector<pair<int, int> > graph[MAX];

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> V >> E;
	cin >> start;
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}
	for (int i = 1; i <= V; i++)
		dist[i] = INF;
	
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (pq.empty() == 0)//큐가 비어있지않으면 반복
	{
		//우선순위큐를 최소힙으로 구현하려면 값을넣고 빼는 연산을 할 때 -를 붙임
		//값이 클 수록 더 높은 우선순위를 가지므로, (2, 3, 5)같이 작은 수부터 사용하게하려면
		//-를 붙여서 (-2, -3, -5)가 들어가도록 해야함
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int ncost = graph[cur][i].second;
			if (dist[next] > cost + ncost)
			{
				dist[next] = cost + ncost;//다음 방문 노드의 거리값 갱신
				pq.push(make_pair(-dist[next], next));
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF)
			cout << "INF" << "\n";
		else
			cout << dist[i] << "\n";
	}

	return (0);
}