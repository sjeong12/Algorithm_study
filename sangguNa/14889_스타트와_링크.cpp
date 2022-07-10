#include <iostream>
#include <math.h>
using namespace std;

int		state[21][21];
bool	check[22];
int		N;
int		answer = 2147483647;

void	DFS(int x, int pos)//x는 카운터 수, pos 는 다음 값
{
	if (x == N / 2)
	{
		int start, link;
		start = 0;
		link = 0;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				//i,j 와 j,i 좌표 값 2개를 더해 start와 link값을 구함
				//true 면 start 짝, false면 link 짝
				if (check[i] == true && check[j] == true)
					start += state[i][j];
				if (check[i] == false && check[j] == false)
					link += state[i][j];
			}
		}

		int temp = abs(start - link);
		if (answer > temp)
			answer = temp;
		
		return ;
	}

	for (int i = pos; i < N; i++)
	{
		check[i] = true;
		DFS(x + 1, i + 1);
		check[i] = false;
	}
}

int main(void)
{
	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> state[i][j];

	DFS(0, 1);
	cout << answer;
}