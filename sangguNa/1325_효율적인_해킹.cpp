#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 10001

int N, M;
vector<int> graph[MAX];
bool visited[MAX];
int cnt;

void DFS(int node_num)
{
	visited[node_num] = true;

	for (int i = 0; i < graph[node_num].size(); i++)
	{
		int next = graph[node_num][i];
		if (!visited[next])
		{
			cnt++;
			DFS(next);
		}
	}
}

int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;
		graph[node2].push_back(node1);
	}

	int node_cnt = 0;
	vector<int> result;

	for (int i = 1; i <= N; i++)
	{
		memset(visited, false, sizeof(visited));
		cnt = 0;

		DFS(i);

		if (node_cnt == cnt)
			result.push_back(i);
		if (node_cnt < cnt)
		{
			node_cnt = cnt;
			result.clear();
			result.push_back(i);
		}
	}

	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ' ';
	cout << '\n';
	return (0);
}