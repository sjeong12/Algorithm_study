#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, K;

	cin >> N >> K;
	queue<int> q;

	for (int i = 0; i < N; i++)
		q.push(i + 1);
	
	cout << '<';
	while (!q.empty())
	{
		for (int i = 0; i < K - 1; i++)
		{
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
		cout << q.front();
		q.pop();
		if (q.empty())
			cout << '>' << '\n';
		else
			cout << ", ";
	}
	return (0);
}