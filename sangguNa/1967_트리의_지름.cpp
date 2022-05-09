#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Node
{
	int		node;
	int		dise;
};

vector<Node> tree[10001];
bool visit[10001] = {false, };
int	maxDist, maxNode;

void	dfs(int node, int dist)
{
	if (visit[node])
		return ;
	if (maxDist < dist)
	{
		maxDist = dist;
		maxNode = node;
	}
	visit[node] = true;
	for (int i = 0; i < tree[node].size(); i++)
	{
		int nextNode = tree[node][i].node;
		int nextDist = tree[node][i].dise;
		dfs(nextNode, nextDist + dist);
	}
}

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, f, t, w;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> f >> t >> w;
		tree[f].push_back({t, w});
		tree[t].push_back({f, w});
	}
	
	dfs(1, 0);
	
	maxDist = 0;
	memset(visit, false, sizeof(visit));
	dfs(maxNode, 0);

	cout << maxDist << '\n';
	return (0);
}