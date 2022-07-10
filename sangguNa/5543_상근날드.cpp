#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int up, mid, down;
	int col, sa;
	int sum = 0;

	cin >> up >> mid >> down;
	cin >> col >> sa;

	sum += min(up, min(mid, down));
	sum += min(col, sa);
	sum -= 50;

	cout << sum << '\n';
	return (0);
}