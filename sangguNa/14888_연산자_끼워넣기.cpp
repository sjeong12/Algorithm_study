#include <iostream>

using namespace std;

int N;
int num[11];
int operators[4];
int mymax = -1000000001;
int mymin = 1000000001;

void go_answer(int result, int idx)
{
	if (idx == N)
	{
		if (result > mymax)
			mymax = result;
		if (result < mymin)
			mymin = result;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (operators[i] > 0)//연산자를 사용한다면
		{
			operators[i]--;//해당 연산자를 한번 사용했으므로 -1
			if (i == 0)
				go_answer(result + num[idx], idx + 1);
			else if (i == 1)
				go_answer(result - num[idx], idx + 1);
			else if (i == 2)
				go_answer(result * num[idx], idx + 1);
			else if (i == 3)
				go_answer(result / num[idx], idx + 1);
			operators[i]++;//다른 연산자도 사용해봐야 하므로 원래대로 돌려줌
		}
	}
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	for (int i = 0; i < 4; i++)
		cin >> operators[i];
	go_answer(num[0], 1);
	cout << mymax << "\n";
	cout << mymin << "\n";
}