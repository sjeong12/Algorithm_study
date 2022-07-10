#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	string stick;
	stack<char> s;
	int ans = 0;

	cin >> stick;
	for (int i = 0; i < stick.length(); i++)
	{
		if (stick[i] == '(')
			s.push(stick[i]);
		else if (stick[i] == ')' && stick[i - 1] == '(')//레이저인 경우
		{
			s.pop();
			ans += s.size();//스택의 사이즈만큼 더해주기
		}
		else//마지막 자투리의 경우
		{
			ans++;
			s.pop();
		}
	}
	cout << ans << "\n";
	return (0);
}