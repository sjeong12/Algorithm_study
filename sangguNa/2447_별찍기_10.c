#include <stdio.h>

char map[2188][2188];

void set_star(int r, int c, int N)
{
	if (N == 1)
	{
		map[r][c] = '*';
		return ;
	}

	int m = N / 3;
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			count++;
			if (count != 5)
				set_star(r + i * m, c + j * m, m);
		}
	}
}

int main(void)
{
	int N;

	scanf("%d", &N);
	for (int i = 0; i < 2188; i++)
		for (int j = 0; j < 2188; j++)
			map[i][j] = ' ';

	set_star(0, 0, N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%c", map[i][j]);
		printf("\n");
	}
	
	return (0);
}