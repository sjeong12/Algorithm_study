#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	int N, x;
	string input;
	queue<int> q;

	cin >> N;
	while (N--)
	{
		cin >> input;
		if (input == "push")
		{
			cin >> x;
			q.push(x);
		}
		else if (input == "pop")
		{
			if (q.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			cout << q.front() << '\n';
			q.pop();
		}
		else if (input == "size")
			cout << q.size() << '\n';
		else if (input == "empty")
			cout << q.empty() << '\n';
		else if (input == "front")
		{
			if (q.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			cout << q.front() << '\n';
		}
		else if (input == "back")
		{
			if (q.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			cout << q.back() << '\n';
		}
	}
	return (0);
}