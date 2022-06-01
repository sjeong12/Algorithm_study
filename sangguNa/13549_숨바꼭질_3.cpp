#include <iostream>
#include <queue>
#include <vector>

#define MAX		100001
using namespace std;

bool isCheck[MAX];

int min_second(int N, int K)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	
	//경과시간을 기준으로 우선순위 큐(시간이 짧을수록 우선순위가 높음)
	pq.push(make_pair(0, N));
	isCheck[N] = true;

	while (!pq.empty())
	{
		int curSec = pq.top().first;
		int curLoc = pq.top().second;
		pq.pop();

		if (curLoc == K)
			return (curSec);
		
		if (curLoc * 2 < MAX && !isCheck[curLoc * 2])
		{
			pq.push(make_pair(curSec, curLoc * 2));
			isCheck[curLoc * 2] = true;
		}

		if (curLoc + 1 < MAX && !isCheck[curLoc + 1])
		{
			pq.push(make_pair(curSec + 1, curLoc + 1));
			isCheck[curLoc + 1] = true;
		}

		if (curLoc - 1 >= 0 && !isCheck[curLoc - 1])
		{
			pq.push(make_pair(curSec + 1, curLoc - 1));
			isCheck[curLoc - 1] = true;
		}
	}
}

int main(void)
{
	int N, K;
	cin >> N >> K;

	cout << min_second(N, K) << '\n';
	return (0);
}