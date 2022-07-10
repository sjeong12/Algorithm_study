#include <iostream>
#include <algorithm>

using namespace std;

bool comp(int a, int b)
{
	if (a > b)
		return (true);
	return (false);
}

//최솟값이 나올려면 A는 오름차순, B는 내림차순으로 정렬하면 됨
int main(void)
{
	int N;
	int arr_a[50];
	int arr_b[50];
	bool check[50];
	int sum = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr_a[i];
	for (int i = 0; i < N; i++)
		cin >> arr_b[i];
	
	sort(arr_a, arr_a + N);//오름차순 정렬
	sort(arr_b, arr_b + N, comp);//내림차순 정렬
	
	for (int i = 0; i < N; i++)
		sum += arr_a[i] * arr_b[i];
	
	cout << sum << "\n";
	return (0);
}