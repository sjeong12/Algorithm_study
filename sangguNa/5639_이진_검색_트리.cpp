#include <iostream>
#include <vector>

using namespace std;

int		tree[10000];

void	postOrder(int start, int end)
{
	if (start >= end)
		return ;
	if (start == end - 1)
	{
		cout << tree[start] << '\n';
		return ;
	}
	int idx = start + 1;
	while (idx < end)
	{
		if (tree[start] < tree[idx])//루트 노드보다 크기가 커지면 오른쪽 노드의 값임
			break;
		idx++;
	}

	postOrder(start + 1, idx);//왼쪽노드
	postOrder(idx, end);//오른쪽노드
	cout << tree[start] << '\n';
}

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int num;
	int input_idx = 0;
	while (cin >> num)
		tree[input_idx++] = num;
	
	postOrder(0, input_idx);

	return (0);
}