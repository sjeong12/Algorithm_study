#include <iostream>

using namespace std;

int main(void)
{
	int score[5];
	int sum = 0, avg = 0;

	for (int i = 0; i < 5; i++)
		cin >> score[i];
	
	for (int i = 0; i < 5; i++)
	{
		if (score[i] < 40)
			score[i] = 40;
		sum += score[i];
	}
	avg = sum / 5;
	cout << avg << '\n';
	return (0);
}