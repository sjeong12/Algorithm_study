#include <iostream>
#include <vector>

using namespace std;

int N;
int T[16] = {0, };
int P[16] = {0, };
int ans[16] = {0, };

int Max(int A, int B)
{
	if (A > B)
		return (A);
	return (B);
}

void DP(void)
{
	int dead_line;

	for (int i = N; i > 0; i--)
	{
		dead_line = i + T[i];
		if (dead_line > N + 1)//상담 불가
			ans[i] = ans[i + 1];
		else //상담 가능, 가장 큰 이익을 비교해서 집어넣기
			ans[i] = Max(ans[i + 1], ans[dead_line] + P[i]);
	}
}

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> T[i] >> P[i];
	
	DP();
	cout << ans[1] << '\n';
	return (0);
}