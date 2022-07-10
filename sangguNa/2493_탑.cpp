#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	stack<pair<int, int> > s;//pair : index, height
	int N, height;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> height;
		while (!s.empty())
		{
			//height 보다 높은 수신탑 찾기
			if (height < s.top().second)
			{
				cout << s.top().first << ' ';//찾았다면 그 수신탑의 index 출력
				break;
			}
			s.pop();//height 보다 작다면 pop
		}
		if (s.empty())//위 과정으로 스택이 비거나, 아예 비어있었다면 0 출력
			cout << 0 << ' ';
		s.push(make_pair(i + 1, height));//height를 스택에 push
	}
	return (0);
}