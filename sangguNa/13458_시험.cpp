#include <iostream>

using namespace std;

int main(void)
{
	long long A[1000000], N;
	long long B, C, t_count = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> B >> C;

	for (int i = 0; i < N; i++)
	{
		long long temp = A[i];
		temp -= B;
		t_count++;
		if (temp < 0)
			continue;
		else if (temp % C == 0)
			t_count += temp / C;
		else if (temp % C != 0)
			t_count += temp / C + 1;
	}

	cout << t_count << '\n';
	return (0);
}