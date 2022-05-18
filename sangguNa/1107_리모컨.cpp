#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;
	char button[11];//고장난 버튼 저장
	bool channel[1000002];//채널을 만들 수 있는지 유무

	cin >> N >> M;
	for (int i = 0; i < M; i++)
		cin >> button[i];

	string num;
	int result1 = 999999999;
	int result2 = 999999999;
	if (N != 100)
	{
		for (int i = 0; i < 1000001; i++)
		{
			channel[i] = true;
			num = to_string(i);
			for (int j = 0; j < M; j++)
			{
				if (num.find(button[j]) != string::npos)//고장난 버튼이면 못만듬
				{
					channel[i] = false;
					break;
				}
			}
		}
		channel[100] = true;

		for (int i = N; i >= 0; i--)
		{
			if (channel[i])
			{
				result1 = i;
				break;
			}
		}

		for (int i = N; i < N + abs(N - 100); i++)
		{
			if (channel[i])
			{
				result2 = i;
				break;
			}
		}

		//각 채널 비교
		//작은 채널까지 가는 데 눌러야하는 수
		//+ 또는 - 버튼 누른 수 + 숫자버튼 누르는 수
		int first = abs(result1 - N) + (to_string(result1).length());

		//큰 채널까지 가는 데 눌러야하는 수
		int second = abs(result2 - N) + (to_string(result2).length());

		//100번에서 + 또는 - 리모컨을 눌러서 가는 수
		int third = abs(100 - N);;

		if (first <= second)
		{
			if (first < third)
				cout << first << '\n';
			else
				cout << third << '\n';
		}
		else if (first > second)
		{
			if (second < third)
				cout << second << '\n';
			else
				cout << third << '\n';
		}
	}
	else
		cout << 0 << '\n';
	return (0);
}