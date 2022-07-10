#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	sort(s.begin(), s.end(), greater<int>());//내림차순 정렬
	//3의 배수 조건
	//1. 1의자리가 0이고
	//2. 각 자리수의 합이 3의 배수여야함
	if (s[s.length() - 1] != '0')
		cout << -1 << '\n';
	else
	{
		long long sum = 0;
		for (auto o : s)//문자열을 숫자로 바꿔 더해줌
			sum += o - '0';
		if (sum % 3 == 0)//자릿수의 합이 3의 배수이면 답
			cout << s << '\n';
		else
			cout << -1 << '\n';
	}
	return (0);
}