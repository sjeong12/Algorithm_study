#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

int b_search(int low, int high)
{
	int sum = 0;
	int mid = (low + high) / 2;

	while (low <= high)
	{
		sum = 0;
		for (int i = 0; i < N; i++)
			sum += (v[i] > mid) ? mid : v[i];
		
		if (sum == M)
			return (mid);
		
		if (sum > M)
			high = mid - 1;
		else
			low = mid + 1;
		
		mid = (low + high) / 2;
	}
	return (mid);
}

int main(void)
{
	cin >> N;

	int high = 0;
	v = vector<int>(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
		if (v[i] > high)
			high = v[i];
	}

	cin >> M;
	cout << b_search(0, high) << '\n';
	return (0);
}