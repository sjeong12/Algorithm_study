#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int N, M;
	string arr[100002];
	map<string, int> m;

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string input;
		cin >> input;
		arr[i] = input;
		m.insert(make_pair(input, i));
	}

	
	while (M--)
	{
		string	s;
		int		i;
		cin >> s;
		if (isdigit(s[0]) == true)
		{
			i = stoi(s);
			cout << arr[i] << '\n';
		}
		else
		{
			auto it = m.find(s);
			cout << it->second << '\n';
		}
	}
	return (0);
}