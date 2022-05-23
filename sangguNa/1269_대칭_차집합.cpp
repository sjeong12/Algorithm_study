#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int A, B, input;

	cin >> A >> B;
	map<int, int> a, b;

	for (int i = 0; i < A; i++)
	{
		cin >> input;
		a[input] = input;
	}

	for (int i = 0; i < B; i++)
	{
		cin >> input;
		b[input] = input;
	}

	int cnt = 0;
	for (map<int, int>::iterator it = a.begin(); it != a.end(); it++)
		if (!b[it->first])
			cnt++;
	for (map<int, int>::iterator it = b.begin(); it != b.end(); it++)
		if (!a[it->first])
			cnt++;

	cout << cnt << '\n';
	return (0);
}