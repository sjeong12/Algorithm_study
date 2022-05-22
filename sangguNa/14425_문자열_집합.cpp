#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int N, M, cnt;
	string s;
	map<string, bool> m;

	cnt = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		m[s] = true;
	}
	
	for (int i = 0; i < M; i++)
	{
		cin >> s;
		if (m[s])
			cnt++;
	}

	cout << cnt << '\n';
	return (0);
}