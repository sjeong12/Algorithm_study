#include <iostream>

using namespace std;

int check_num(int &a, int &b, int &c)
{
	if (a == b && b == c && c == a)
		return (a);
	else if ((a == b && b != c && c != a)
			|| (a != b && b == c && c != a)
			|| (a != b && b != c && c == a))
	{
		if (a == b && b != c && c != a) 
			return (10 + a);
		else if (a != b && b == c && c != a)
			return (10 + b);
		else if (a != b && b != c && c == a)
			return (10 + c);
	}
	else if (a != b && b != c && c != a)
		return (100 + max(a, max(b, c)));
	return (0);
}

int main(void)
{
	int a, b, c;
	int reword, check;

	cin >> a >> b >> c;
	check = check_num(a, b, c);
	if (check / 10 == 0)
		cout << 10000 + check * 1000 << '\n';
	else if (check / 10 == 1)
		cout << 1000 + (check % 10) * 100 << '\n';
	else if (check / 10 == 10)
	{
		//int big = max(a, max(b, c));
		cout << 100 * (check % 100) << '\n';
	}
	return (0);
}