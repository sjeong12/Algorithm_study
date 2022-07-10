#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, K;
	int sum, idx;
	int max_num = -987654321;

	cin >> N >> K;

	vector<int> num(N);
	for (int i = 0; i < N; i++)
		cin >> num[i];
	
	sum = 0;
	idx = 0;
	for (int i = 0; i < N; i++)
	{
		sum += num[i];
		idx++;
		if (idx == K)
		{
			max_num = max(max_num, sum);
			sum -= num[i - K + 1];//연속한 날의 합이므로 다음 단계로 넘어가기 위해 첫날 값을 빼줌
			idx--;
		}
	}
	cout << max_num << '\n';
	return (0);
}