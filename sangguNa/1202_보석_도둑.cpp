#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, K;
	int bag[300000];
	pair<int, int> jewel[300000];
	priority_queue<int> pq;

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> jewel[i].first >> jewel[i].second;
	for (int i = 0; i < K; i++)
		cin >> bag[i];
	
	//보석과 가방을 오름차순으로 정렬(보석은 무게를 기준으로 정렬됨)
	sort(jewel, jewel + N);
	sort(bag, bag + K);

	long long res = 0;
	int idx = 0;
	for (int i = 0; i < K; i++)
	{
		//i번째 가방의 무게보다 작거나 같은 보석을 다 넣음
		while (idx < N && jewel[idx].first <= bag[i])
			pq.push(jewel[idx++].second);
		
		//pq의 루트에는 현재 기준으로 가장 비싼 보석이 있음
		if (!pq.empty())
		{
			res += pq.top();
			pq.pop();
		}
	}
	cout << res << '\n';
	return (0);
}