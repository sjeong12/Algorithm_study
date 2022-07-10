#include <iostream>
#include <vector>

using namespace std;

int n, k, root, leaf = 0;
vector<int> tree[51];

int dfs(int node)
{
	if (node == k)//입력된 노드가 지워야하는 노드면 -1 반환
		return (-1);
	if (!tree[node].size())//해당 노드의 크기가 0, 즉 자식노드가 없으면 리프노드이므로 갯수 증가
	{
		leaf++;
		return (0);
	}
	for (int i = 0; i < tree[node].size(); i++)
	{
		int temp = dfs(tree[node][i]);
		if (temp == -1 && tree[node].size() == 1)//지우려는 노드이고, 해당 노드에 자식노드가 1개뿐이면
			leaf++;//부모가 리프노드가 되므로 갯수 증가
	}
	return (0);
}

int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int input;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (input == -1)
			root = i;
		else
			tree[input].push_back(i);
	}
	cin >> k;
	
	dfs(root);
	cout << leaf << '\n';
	return (0);
}