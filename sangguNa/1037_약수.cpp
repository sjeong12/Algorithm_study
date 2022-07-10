#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	int arr[51];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	sort(arr, arr + n);//정렬 후
	//만약 가장 작은 수가 N의 약수라면 그 몫도 N의 약수이다.
	//따라서 최솟값과 최대값을 곱한 게 N을 구한것
	int ans = arr[0] * arr[n - 1];
	cout << ans << '\n';
}