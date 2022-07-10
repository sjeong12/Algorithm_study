#include <iostream>
#include <queue>

using namespace std;

#define MAX 101

int N, M, p1, p2;
int cnt = 0;
int arr[MAX][MAX];
int check[MAX];
queue<int> q;

void BFS(int input)
{
	int front;

	q.push(input);
	while (!q.empty())
	{
		front = q.front();
		q.pop();
		for (int i = 1; i <= N; i++)
		{
			if (arr[front][i] != 0 && !check[i])//관계가 있고, 촌수 계산이 안되어있으면
			{
				q.push(i);
				check[i] = check[front] + 1;//촌수 카운트 증가
			}
		}
	}
}

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	cin >> p1 >> p2;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}

	BFS(p1);

	if (check[p2] == 0)
		check[p2] = -1;
	
	cout << check[p2] << '\n';
	return (0);
}