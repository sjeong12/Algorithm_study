#include <iostream>

using namespace std;

typedef struct  s_node
{
	char		t_left;
	char		t_right;
}               t_node;

t_node	tree[27];

void	preorder(int N)//전위 순회 : 루트 노드->왼쪽 트리->오른쪽 트리
{
	if (N == -1)
		return ;
	cout << static_cast<char>(N + 'A');
	preorder(tree[N].t_left);
	preorder(tree[N].t_right);
}

void	inorder(int N)//중위 순회 : 왼쪽 트리->루트 노드->오른쪽 트리
{
	if (N == -1)
		return ;
	inorder(tree[N].t_left);
	cout << static_cast<char>(N + 'A');
	inorder(tree[N].t_right);
}

void	postorder(int N)//후위 순회 : 왼쪽 트리->오른쪽 트리->루트 노드
{
	if (N == -1)
		return ;
	postorder(tree[N].t_left);
	postorder(tree[N].t_right);
	cout << static_cast<char>(N + 'A');
}

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int	N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char root, left, right;
		cin >> root >> left >> right;
		root = root - 'A';
		if (left == '.')
			tree[root].t_left = -1;
		else
			tree[root].t_left = left - 'A';
		if (right == '.')
			tree[root].t_right = -1;
		else
			tree[root].t_right = right - 'A';
	}

	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);

	return (0);
}