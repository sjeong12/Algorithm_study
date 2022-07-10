#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> modem;
	int N, C;
	int left, right, mid;
	int answer;

	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		modem.push_back(input);
	}

	sort(modem.begin(), modem.end());
	
	left = 0;
	right = modem.back();
	answer = -1;

	while (left <= right)
	{
		mid = (left + right) / 2;
		int prev_index = 0;
		int set_num = 1;

		//하나하나 건너뛰면서, 공유기의 거리 차이가 mid 이상인 경우에만 설치 가능
		for (int i = 1; i < N; i++)
		{
			if (modem.at(i) - modem.at(prev_index) >= mid)
			{
				prev_index = i;
				set_num++;
			}
		}

		//이분 탐색에 의해, set_num 크기에 따라 left, right 변경
		//set_num 이 c보다 크면 현재의 최댓값이 되며, left를 변경하여 더 큰값 탐색
		//현재의 설치 대수보다 더 크면 answer 교체
		if (set_num >= C)
		{
			answer = mid;
			left = mid + 1;
		}
		else//반대의 경우 right 수정
			right = mid - 1;
	}
	cout << answer << endl;
	return (0);
}