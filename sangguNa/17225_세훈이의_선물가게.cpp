#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Order
{
	int		time;
	char	color;
	Order(int t, int c)
	{
		time = t;
		color = c;
	}
	bool operator< (const Order &b) const
	{
		if (time == b.time)
			return color > b.color;//시간이 같으면 상민이가 먼저 시작하도록
		return (time > b.time);
	}
};

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int A, B, N;
	cin >> A >> B >> N;

	priority_queue<Order> pq;
	int bEnd = -1;
	int rEnd = -1;
	for (int i = 0; i < N; i++)
	{
		int t, m;
		char c;
		cin >> t >> c >> m;

		if (c == 'B')
		{
			if (bEnd > t)//아직 앞 주문이 끝나지 않은 상태면
				t = bEnd;//끝나는 시점을 기억하고 있다가 그때부터 시작
			for (int j = 0; j < m; j++)
				pq.push(Order((t + A * j), 'B'));
			bEnd = (t + A * m);//현재 주문이 끝나는 시간 업데이트
		}
		else if (c == 'R')
		{
			if (rEnd > t)
				t = rEnd;
			for (int j = 0; j < m; j++)
				pq.push(Order((t + B * j), 'R'));
			rEnd = (t + B * m);
		}
	}

	vector<int> sangmin;
	vector<int> jisu;

	int idx = 1;
	while (!pq.empty())
	{
		char color = pq.top().color;
		pq.pop();

		if (color == 'B')
			sangmin.push_back(idx);
		else
			jisu.push_back(idx);
		idx++;
	}
	cout << sangmin.size() << '\n';
	for (int i = 0; i < sangmin.size(); i++)
		cout << sangmin[i] << " ";
	cout << '\n';

	cout << jisu.size() << '\n';
	for (int i = 0; i < jisu.size(); i++)
		cout << jisu[i] << " ";
	cout << '\n';

	return (0);
}