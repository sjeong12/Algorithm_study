#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, K;

	cin >> N >> K;

	int left = 1, right = K, mid;
	int ans = 0;

	for (;;)
	{
		if (left > right)
			break;
		mid = (left + right) / 2;
		int cnt = 0;
		//배열 크기(원소 갯수) 와 mid / i(mid 보다 작거나 같은 원소 갯수)를 비교
		//작은 값을 cnt에 더해줌
		for (int i = 1; i <= N; i++)
			cnt += min(N, mid / i);
		if (cnt >= K)
		{
			ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << ans << "\n";
	return (0);
}