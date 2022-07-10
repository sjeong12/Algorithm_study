#include <iostream>
#include <cstring>
#define MAX 100001

using namespace std;

int N, cnt;
int want[MAX];
bool visited[MAX];
bool done[MAX];//방문이 완전히 끝났는지 여부

void DFS(int node_num)
{
	visited[node_num] = true;
	int next = want[node_num];
	if (!visited[next])
		DFS(next);
	else if (!done[next])
	{
		for (int i = next; i != node_num; i = want[i])
			cnt++;
		cnt++;//자기 자신을 세는 부분
	}
	done[node_num] = true;
}

int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--)
	{
		memset(visited, false, sizeof(visited));
		memset(done, false, sizeof(done));

		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> want[i];
		
		cnt = 0;
		for (int i = 1; i <= N; i++)
			if (!visited[i])
				DFS(i);//팀을 이루는 사람의 수를 카운트
		cout << N - cnt << '\n';
	}

	return (0);
}