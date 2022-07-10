#include <iostream>

using namespace std;

int main(void)
{
	int A, B, res;

	while (1)
	{
		cin >> A >> B;
		if (A == 0 && B == 0)
			break;
		else if (A == 0 || B == 0)
		{
			cout << "neither" << '\n';
			continue;
		}
		
		if (A <= B)
		{
			if (B % A == 0)
				cout << "factor" << '\n';
			else
				cout << "neither" << '\n';
		}
		else if (A > B)
		{
			if (A % B == 0)
				cout << "multiple" << '\n';
			else
				cout << "neither" << '\n';
		}
	}

	return (0);
}