#include <iostream>
using namespace std;

int K, N, ans;
int max_len;
int line[10001];
long long front, rear, mid;

int main(void)
{
	int cnt;

	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		cin >> line[i];
		if (max_len < line[i])
			max_len = line[i];
	}

	front = 1;
	rear = max_len;//범위를 길이 1부터 가장큰 길이까지로 설정
	ans = 0;

	while (front <= rear)
	{
		mid = (front + rear) / 2;
		cnt = 0;
		for (int i = 0; i < K; i++)
			cnt += line[i] / mid;//현재 길이로 잘랐을때 몇개 나오는지 카운트
		
		if (cnt >= N)//요구사항보다 많으면
		{
			front = mid + 1;//전선의 길이를 늘림
			if (ans < mid)
				ans = mid;
		}
		else//cnt < N인 경우, 즉 요구사항보다 적으면
		{
			rear = mid - 1;//전선의 길이를 줄임
		}
	}
	cout << ans << "\n";
	return (0);
}