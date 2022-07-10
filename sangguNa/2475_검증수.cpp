#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int a[5];
	int sum, ans;

	for (int i = 0; i < 5; i++)
		cin >> a[i];
	
	sum = 0;
	for (int i = 0; i < 5; i++)
	{
		int temp = a[i];
		sum += (temp * temp);

	}
	ans = sum % 10;
	cout << ans << '\n';
	return (0);
}