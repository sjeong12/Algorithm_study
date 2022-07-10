#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool isCheck[100001];

int main(void)
{
	int N, K;
	int answer = 0;
	int locate, cost;
	int x_1, x_2, x_3;
	
	cin >> N >> K;
	queue<pair<int, int>> q;
	q.emplace(N, 0);//최초위치, 시간(0)을 집어넣음

	while (!q.empty())
	{
		locate = q.front().first;//현재위치
		cost = q.front().second;//현재까지의 시간
		q.pop();

		if (locate == K)//현재 위치가 목적지에 도달했으면 시간을 답 변수에다 저장
		{
			answer = cost;
			break;
		}

		x_1 = locate - 1;
		x_2 = locate + 1;
		x_3 = locate * 2;

		//3가지의 이동을 모두 수행해보고 큐에다 집어넣음
		if (x_1 >= 0 && !isCheck[x_1])
		{
			isCheck[x_1] = true;
			q.emplace(x_1, cost + 1);
		}

		if (x_2 <= K && !isCheck[x_2])
		{
			isCheck[x_2] = true;
			q.emplace(x_2, cost + 1);
		}

		if (x_3 <= K + 1 && !isCheck[x_3])
		{
			isCheck[x_3] = true;
			q.emplace(x_3, cost + 1);
		}
	}

	cout << answer << "\n";
	return (0);
}