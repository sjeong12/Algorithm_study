//그리디 알고리즘
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	vector<int> pos;
	vector<int> neg;
	vector<int> zero;
	vector<int> ans;
	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num > 0)
		{
			if (num == 1)
				ans.push_back(num);
			else
				pos.push_back(num);
		}
		else if (num < 0)
			neg.push_back(num);
		else
			zero.push_back(num);
	}

	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());

	int p_size = pos.size();
	if (p_size % 2 != 0)
		ans.push_back(pos[0]);
	for (int i = p_size - 1; i > 0; i -= 2)
	{
		int big = pos[i];
		int small = pos[i - 1];
		int res = big * small;
		ans.push_back(res);
	}

	int n_size = neg.size();
	if (n_size % 2 != 0)
	{
		if (zero.size() > 0)
			zero.pop_back();
		else
			ans.push_back(neg[n_size - 1]);
	}
	for (int i = 0; i < n_size - 1; i += 2)
	{
		int small = neg[i];
		int big = neg[i + 1];
		int res = small * big;
		ans.push_back(res);
	}

	int sum = 0;
	for (int i = 0; i < ans.size(); i++)
		sum += ans[i];
	cout << sum << '\n';
	return (0);
}