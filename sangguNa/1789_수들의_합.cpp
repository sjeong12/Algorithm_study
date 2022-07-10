#include <iostream>

using namespace std;

int main(void)
{
	unsigned long long S, sum = 0;
	int num = 1;//1부터 더해나가야 N의 최대값을 구할 수 있음
	int result = 0;
	
	cin >> S;

	while (1)
	{
		sum += num;
		result++;
		if (sum > S)//만약 합이 S를 넘어가면 마지막에 더한 숫자를 수정하면됨
		{
			result--;//N의 최댓값을 하나 줄임
			break;
		}
		num++;
	}

	cout << result << '\n';
	return (0);
}