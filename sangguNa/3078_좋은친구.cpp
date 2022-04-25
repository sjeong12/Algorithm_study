#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, K;
	queue<int> q[21];
	long long cnt = 0;

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;

		int len = input.length();

		while (!q[len].empty() && i - q[len].front() > K)
			q[len].pop();
		
		cnt += q[len].size();
		q[len].push(i);
	}

	cout << cnt << '\n';
	return (0);
}