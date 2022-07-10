#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareWidth(string a, string b)
{
	if (a.length() == b.length())//길이가 같으면 사전순인지
		return a < b;
	return (a.length() < b.length());//다르면 길이 순으로 리턴
}

int main(void)
{
	int N;
	vector<string> vec;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		//중복 제거, 중복이 없으면 find 함수가 vector.end() 를 반환함
		if (find(vec.begin(), vec.end(), str) == vec.end())
			vec.push_back(str);
	}
	sort(vec.begin(), vec.end(), compareWidth);
	for (int i = 0; i < vec.size(); i++)//중복이 제거되었을 수도 있으니 vec.size()만큼 반복
		cout << vec[i] << "\n";
	return (0);
}