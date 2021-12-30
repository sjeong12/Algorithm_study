#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1001];
int sum = 0, all_sum = 0;

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	sort(arr, arr + N);

	for (int i = 0; i < N; i++)
	{
		sum += arr[i];
		all_sum += sum;
	}

	cout << all_sum << endl;
}