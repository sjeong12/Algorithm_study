//그리디 알고리즘
#include <iostream>

using namespace std;

int main(void)
{
	int a, b;
	cin >> a >> b;

	int cnt = 0;
	while (1)//b에서 a를 만드는, 거꾸로 되돌아가는 방법
	{
		if (a > b)//a가 b보다 크면 a로 b를 만들 수 없음
		{
			cout << -1 << '\n';
			break;
		}
		if (a == b)
		{
			cout << cnt + 1 << '\n';
			break;
		}
		if (b % 10 == 1)
			b /= 10;//1이 있으면 1을 제거하기위해 나누기 연산 및 몫을 남기기
		else if (b % 2 == 0)
			b /= 2;//2의 배수이면 2로 나누기
		else//그 외는 만들 수 없으므로 -1 출력
		{
			cout << -1 << '\n';
			break;
		}
		cnt++;
	}
	return (0);
}