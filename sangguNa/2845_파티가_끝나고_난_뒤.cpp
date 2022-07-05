#include <iostream>

using namespace std;

int main(void)
{
	int L, P, total;
	int post[5];

	cin >> L >> P;
	total = L * P;
	for (int i = 0; i < 5; i++)
		cin >> post[i];
	
	for (int i = 0; i < 5; i++)
		cout << post[i] - total << ' ';
	cout << '\n';

	return (0);
}