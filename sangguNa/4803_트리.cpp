#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, from, to;
int ans, cnt;
bool visit[501];
vector<int> graph[501];

bool	DFS(int x, int post_x)
{
	visit[x] = true;

	for (int i = 0; i < graph[x].size(); i++)
	{
		if (graph[x][i] == post_x)
			continue;
		if (visit[graph[x][i]])
			return (false);
		if (DFS(graph[x][i], x) == false)
			return (false);
	}
	return (true);
}

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (true)
	{
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		
		//벡터 및 방문여부 배열 초기화
		cnt++;
		ans = 0;
		for (int i = 1; i <= N; i++)
		{
			graph[i].clear();
			visit[i] = false;
		}

		for (int i = 0; i < M; i++)
		{
			cin >> from >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);
		}

		for (int i = 1; i <= N; i++)
			if (!visit[i])
				if (DFS(i, 0))
					ans++;
		
		cout << "Case " << cnt << ": ";
		if (ans > 1)
			cout << "A forest of " << ans << " trees." << '\n';
		else if (ans == 1)
			cout << "There is one tree." << '\n';
		else if (ans == 0)
			cout << "No trees." << '\n';
	}
	return (0);
}