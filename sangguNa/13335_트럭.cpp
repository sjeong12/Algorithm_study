#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int N, W, L;
	int truck[1000];

	cin >> N >> W >> L;
	for (int i = 0; i < N; i++)
		cin >> truck[i];
	
	queue<int> q;

	int curLoad = 0, time = 0;
	for (int i = 0; i < N; i++)
	{
		while (1)
		{
			if (q.size() == W)
			{
				curLoad -= q.front();
				q.pop();
			}
			if (truck[i] + curLoad <= L)
				break;
			q.push(0);
			time++;
		}
		q.push(truck[i]);
		time++;
		curLoad += truck[i];
	}
	cout << time + W << '\n';
	return (0);
}