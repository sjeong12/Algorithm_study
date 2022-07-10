#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R;
vector<int> graph[100001];
vector<int> dist(100001, 0);
int idx = 1;

void dfs(int cur)
{
	dist[cur] = idx++;
	for (auto &next : graph[cur])
	{
		if (dist[next] != 0)
			continue;
		dfs(next);
	}
}

int main(void)
{
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++)
	{
		int a, b;

		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	for (int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());
	
	dfs(R);
	for (int i = 1; i <= N; i++)
		cout << dist[i] << '\n';
	
	return (0);
}