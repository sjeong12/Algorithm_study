#include <iostream>

using namespace std;

int main(void)
{
	int N, sum;

	cin >> N;
	sum = (N * (1 + N)) / 2;
	cout << sum << '\n';
	return (0);
}