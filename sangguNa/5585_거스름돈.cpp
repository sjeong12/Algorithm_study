#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int pay, remain, count = 0;

	cin >> pay;
	remain = 1000 - pay;
	
	count += remain / 500;
	count += (remain % 500) / 100;
	count += ((remain % 500) % 100) / 50;
	count += (((remain % 500) % 100) % 50) / 10;
	count += ((((remain % 500) % 100) % 50) % 10) / 5;
	count += (((((remain % 500) % 100) % 50) % 10) % 5) / 1;

	cout << count;
	return (0);
}