#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	int T, n;
	string func, arr;

	cin >> T;
	while (T--)
	{
		cin >> func;
		cin >> n;
		cin >> arr;

		deque<int> dq;
		string temp;
		for (int i = 0; i < arr.length(); i++)
		{
			if (arr[i] == '[')
				continue;
			else if (arr[i] >= '0' && arr[i] <= '9')
				temp += arr[i];
			else if (arr[i] == ',' || arr[i] == ']')//, 나 ] 을 만났다면
			{
				if (!temp.empty())//저장해놓은 값이 temp에 남아있으면
				{
					dq.push_back(stoi(temp));//문자열을 정수로 바꾼 뒤 덱에 넣음
					temp.clear();//안의 내용들을 지워줌
				}
			}
		}

		bool print = true;//error 가 아닐 경우 true
		bool left = true;//뒤집어진 상태가 아니면 true
		for (int i = 0; i < func.length(); i++)
		{
			if (func[i] == 'R')
				left = !left;
			else
			{
				if (dq.empty())
				{
					print = false;
					cout << "error" << "\n";
					break;
				}
				else
				{
					if (left)
						dq.pop_front();
					else
						dq.pop_back();
				}
			}
		}

		if (print)//정상인 경우
		{
			if (left)//뒤바뀐 상태가 아닌 경우
			{
				cout << "[";
				while (!dq.empty())
				{
					cout << dq.front();//앞에서부터 차례대로 출력
					dq.pop_front();
					if (!dq.empty())
						cout << ",";
				}
				cout << "]" << "\n";
			}
			else//뒤집어진 상태의 경우
			{
				cout << "[";
				while (!dq.empty())
				{
					cout << dq.back();//뒤에서부터 차례대로 출력
					dq.pop_back();
					if (!dq.empty())
						cout << ",";
				}
				cout << "]" << "\n";
			}
		}
	}

	return (0);
}