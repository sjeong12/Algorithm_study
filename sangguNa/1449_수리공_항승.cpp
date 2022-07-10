#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, L;
	int ans = 1;

	cin >> N >> L;
	vector<int> leaks(N);
	for (int i = 0; i < N; i++)
		cin >> leaks[i];

	sort(leaks.begin(), leaks.end());
	
	int st = leaks[0];
	for (int i = 1; i < N; i++)
	{
		if (leaks[i] - st + 1 > L)
		{
			ans++;
			st = leaks[i];
		}
	}

	cout << ans << '\n';
	return (0);
}