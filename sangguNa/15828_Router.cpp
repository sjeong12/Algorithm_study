#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, input;
	queue<int> router;

	cin >> N;
	while (true)
	{
		cin >> input;
		if (input == 0)
			router.pop();
		else if (input == -1)
			break;
		else
		{
			if (router.size() == N)
				continue;
			router.push(input);
		}
	}

	if (!router.empty())
	{
		while (!router.empty())
		{
			cout << router.front() << ' ';
			router.pop();
		}
	}
	else
		cout << "empty" << '\n';
	
	return (0);
}