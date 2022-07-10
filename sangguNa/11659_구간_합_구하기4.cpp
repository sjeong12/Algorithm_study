#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;
	int a, b, res;

	cin >> N >> M;
	vector<int> input(N);
	vector<int> sum(N + 1);
	for (int i = 0; i < N; i++)
		cin >> input[i];

	for (int i = 0; i < N; i++)
	{
		if (i == 0)
			sum[i + 1] = input[i];
		else
			sum [i + 1] = sum[i] + input[i];
	}

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		res = sum[b] - sum[a - 1];
		cout << res << '\n';
	}

	return (0);
}