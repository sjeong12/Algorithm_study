#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, temp;
	int rope[100000];
	int result = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> rope[i];
	
	sort(rope, rope + N, greater<int>());//내림차순으로 정렬

	//로프 * 갯수의 값을 구해서 가장 큰 값이 최대 하중이됨
	for (int i = 0; i < N; i++)
	{
		temp = rope[i] * (i + 1);
		if (result < temp)
			result = temp;
	}

	cout << result << endl;
}