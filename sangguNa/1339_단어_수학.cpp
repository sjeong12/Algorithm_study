#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> word;
int result = 0;
int alpha[26];

void calculate()
{
	for (int i = 0; i < word.size(); i++)
	{
		int pow = 1;
		for (int j = word[i].size() - 1; j >= 0; j--)
		{
			int val = word[i][j] - 'A';
			alpha[val] += pow;//해당 알파벳에 10의 제곱값을 넣어줌
			pow *= 10;
		}
	}
	sort(alpha, alpha + 26);
	int num = 9;
	for (int i = 25; i >= 0; i--)
	{
		if (alpha[i] == 0)
			continue;
		result += (alpha[i] * num);
		num--;
	}
}

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int num;
	string ss;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> ss;
		word.push_back(ss);
	}
	calculate();
	cout << result << '\n';
	return (0);
}