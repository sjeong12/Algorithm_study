#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	priority_queue<int, vector<int>, greater<int> > pq;//오름차순으로 정렬되도록 우선순위큐 생성

	cin >> N;
	if (N == 1)//묶음갯수가 1개뿐이면 연산이 필요없음
	{
		cout << 0 << '\n';
		return (0);
	}

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		pq.push(input);
	}

	int answer = 0;
	while (pq.size() > 1)
	{
		int a, b;
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		answer = answer + a + b;
		pq.push(a + b);
	}

	cout << answer << '\n';
	return (0);
}