#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, M;
	int num, index;
	int count = 0;
	deque<int> d;

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		d.push_back(i);
	
	while (M--)
	{
		cin >> num;
		for (int i = 0; i < d.size(); i++)
		{
			if (d[i] == num)
			{
				index = i;
				break;
			}
		}
		if (index < d.size() - index)//왼쪽에 더 가까운 경우
		{
			while (1)
			{
				if (d.front() == num)
				{
					d.pop_front();
					break;
				}
				++count;
				d.push_back(d.front());
				d.pop_front();
			}
		}
		else
		{
			while (1)
			{
				if (d.front() == num)
				{
					d.pop_front();
					break;
				}
				++count;
				d.push_front(d.back());
				d.pop_back();
			}
		}
	}
	cout << count << "\n";
	return (0);
}