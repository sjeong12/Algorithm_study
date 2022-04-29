#include <iostream>
#include <vector>

#define A_MAX	100000 + 1

using namespace std;

int N;
bool check[A_MAX];
int parent[A_MAX];
vector<int> tree[A_MAX];

void find_parent(int nodeNum)
{
	check[nodeNum] = true;

	for (int i = 0; i < tree[nodeNum].size(); i++)
	{
		int next = tree[nodeNum][i];
		if (!check[next])
		{
			parent[next] = nodeNum;//next 노드의 부모노드는 nodeNum
			find_parent(next);
		}
	}
}

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;

		tree[n1].push_back(n2);
		tree[n2].push_back(n1);
	}

	find_parent(1);

	for (int i = 2; i <= N; i++)//2번 노드의 부모부터 출력
		cout << parent[i] << '\n';
	
	return (0);
}