#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
//그리디 알고리즘
int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string number;
	int zero = 0, one = 0;

	cin >> number;

	for (int i = 0; i < number.size(); i++)
	{
		if (number[i] != number[i + 1])//서로 다른 영역을 만난경우
		{
			if (number[i] == '0')//왼쪽을 기준으로 봐서 0이면 0카운트 증가
				zero++;
			else//1이면 1카운트 증가
				one++;
		}
	}

	cout << min(zero, one) << '\n';
	return (0);
}