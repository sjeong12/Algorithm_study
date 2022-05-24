#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	string		s;
	vector<string> s_str;
	cin >> s;

	int len = s.size();
	int l = 1;

	while (len >= l)
	{
		for (int i = 0; i <= len - l; i++)
			s_str.push_back(s.substr(i, l)); //부분 문자열을 vector에 push
		l++;
	}

	sort(s_str.begin(), s_str.end());//중복제거를 위해, 먼저 정렬
	s_str.erase(unique(s_str.begin(), s_str.end()), s_str.end());//중복 제거
	cout << s_str.size() << '\n';

	return (0);
}