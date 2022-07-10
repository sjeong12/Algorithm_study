#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int> > A(51, vector<int>(51, 0));
vector<vector<int> > B(51, vector<int>(51, 0));
vector<vector<bool> > trans(51, vector<bool>(51, false));

void change(int n, int m)
{
	for (int i = n; i < n + 3; i++)
		for (int j = m; j < m + 3; j++)
			trans[i][j] = !trans[i][j];
}

int main(void)
{
	int N, M;
	char c;
	int ans = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++)//A행렬 입력
	{
		for (int j = 0; j < M; j++)
		{
			cin >> c;
			A[i][j] = c - 48;
		}
	}
	for (int i = 0; i < N; i++)//B행렬 입력
	{
		for (int j = 0; j < M; j++)
		{
			cin >> c;
			B[i][j] = c - 48;
			if (B[i][j] != A[i][j])//다른 부분이 있으면 true로 체크
				trans[i][j] = true;
		}
	}

	if (N < 3 || M < 3)//3,3 행렬보다 작으면 3x3으로 바꾸는 시도를 못하므로
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (trans[i][j])//처음부터 같지않으면 -1 출력
				{
					ans = -1;
					break;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i <= N - 3; i++)
		{
			for (int j = 0; j <= M - 3; j++)
			{
				if (trans[i][j] == true)
				{
					change(i, j);//3x3 범위 뒤집기
					ans++;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (trans[i][j])
				ans = -1;
	
	cout << ans << '\n';
	return (0);
}