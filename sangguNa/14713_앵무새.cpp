#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<queue<string> > q(N + 1);
	string temp;

	getline(cin, temp);//위에서 cin으로 정수 입력받고 남은 개행문자 처리
	for (int i = 0; i < N + 1; i++)
	{
		getline(cin, temp);
		istringstream ss(temp);
		string stringbuffer;
		while (getline(ss, stringbuffer, ' '))
			q[i].push(stringbuffer);
	}

	bool check = false;
	int queue_size = q[N].size();
	for (int i = 0; i < queue_size; i++)
	{
		string base_word = q[N].front();
		for (int j = 0; j < N; j++)
		{
			if (!q[j].empty() && q[j].front() == base_word)
			{
				q[j].pop();
				q[N].pop();
				check = true;
				break;
			}
		}
		if (check == false)
		{
			cout << "Impossible\n";
			return (0);
		}
		else
			check = false;
	}

	for (int i = 0; i < N; i++)
	{
		if (!q[i].empty())
		{
			cout << "Impossible\n";
			return (0);
		}
	}
	cout << "Possible\n";
	return (0);
}