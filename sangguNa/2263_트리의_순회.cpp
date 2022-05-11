#include <iostream>

using namespace std;

int N;
int inOrder[100001];//중위 순회 저장
int postOrder[100001];//후위 순회 저장

//중위 순회(s1 ~ e1) : L / root / R
//후위 순회(s2 ~ e2) : L / R / root
void	DFS(int s1, int e1, int s2, int e2)
{
	if (s1 > e1 || s2 > e2)
		return ;
	int root = postOrder[e2];//후위 순회의 끝은 루트 노드
	int idx = -1;
	for (int i = s1; i <= e1; i++)
	{
		if (inOrder[i] == root)//중위 순회에서 루트 노드의 위치 찾기
		{
			idx = i;
			break;
		}
	}
	int l_count = idx - s1;//Left 갯수
	
	cout << root << ' ';
	//Left 노드
	DFS(s1, idx - 1, s2, s2 + l_count - 1);
	//Right 노드
	DFS(idx + 1, e1, s2 + l_count, e2 - 1);
}

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> inOrder[i];
	for (int i = 0; i < N; i++)
		cin >> postOrder[i];
	
	DFS(0, N - 1, 0, N - 1);
	return (0);
}