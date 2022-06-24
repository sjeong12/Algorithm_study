#include <iostream>

using namespace std;

int main(void)
{
	int H, M;
	int cost = 0;
	int wait_h, wait_m;

	cin >> H >> M;
	cin >> cost;

	wait_h = cost / 60;
	wait_m = cost % 60;
	H += wait_h;
	M += wait_m;

	if (M >= 60)
	{
		int temp = M / 60;
		M %= 60;
		H += temp;
	}
	if (H >= 24)
		H %= 24;
	cout << H << ' ' << M << '\n';
	return (0);
}