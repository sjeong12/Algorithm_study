#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int N, M;
	int num;

	vector<int>::iterator lower;
	vector<int>::iterator upper;
	vector<int> v;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &num);
		lower = lower_bound(v.begin(), v.end(), num);
		upper = upper_bound(v.begin(), v.end(), num);

		printf("%d ", upper - lower);
	}

	return (0);
}