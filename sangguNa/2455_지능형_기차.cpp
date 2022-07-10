#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int out, in, remain = 0;
	int temp = 0;

	for (int i = 0; i < 4; i++)
	{
		cin >> out >> in;
		remain = remain - out + in;
		temp = max(temp, remain);
	}
	cout << temp << '\n';
	return (0);
}