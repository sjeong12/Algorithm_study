#include <iostream>

using namespace std;

bool map[1001][1001];
bool check[1001];
int N, M, result;

void dfs(int num)
{
	check[num] = true;

	for (int i = 1; i <= N; i++)
		if (map[num][i] && !check[i])
			dfs(i);
}

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++)//간선을 입력받음 | a, b를 입력받으면 (a,b), (b,a)가 연결된것임
	{
		int a, b;

		cin >> a >> b;
		map[a][b] = true;//양방향으로 연결되있다고 표기
		map[b][a] = true;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!check[i])//check가 안된 곳을 기준으로 탐색
		{
			result++;//연결 요소 갯수 추가
			dfs(i);
		}
	}

	cout << result << '\n';
}