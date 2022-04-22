#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, count, temp;
	queue<int> q;

	cin >> N;
	for (int i = 0; i < N; i++)
		q.push(i + 1);
	
	count = 0;
	while (!q.empty())
	{
		if (count == 0)
		{
			cout << q.front() << ' ';
			q.pop();
			count = 1;
		}
		else if (count == 1)
		{
			temp = q.front();
			q.pop();
			q.push(temp);
			count = 0;
		}
	}
	return (0);
}