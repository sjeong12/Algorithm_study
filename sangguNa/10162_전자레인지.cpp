#include <iostream>
#include <vector>

using namespace std;

#define A 300
#define B 60
#define C 10

int main(void)
{
	int N, answer;
	int ac = 0, bc = 0, cc = 0;
	
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	if (N % 10 != 0)
		cout << "-1" << '\n';
	else
	{
		ac = N / A;
		bc = (N % A) / B;
		cc = ((N % A) % B) / C;
		cout << ac << ' ' << bc << ' ' << cc << '\n';
	}
	return (0);
}