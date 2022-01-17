#include <stdio.h>

int arr[64][64];//읽어온 값을 저장하는 배열
char input[65];//한줄한줄을 읽어오는 배열
int N;

void divide(int x, int y, int size)
{
	int temp;

	temp = arr[x][y];
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (temp != arr[i][j])
			{
				printf("(");
				divide(x, y, size/2);
				divide(x, y + size/2, size/2);
				divide(x + size/2, y, size/2);
				divide(x + size/2, y + size/2, size/2);
				printf(")");
				return ;
			}
		}
	}

	if (temp == 1)
		printf("1");
	else if (temp == 0)
		printf("0");
}

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", input);
		for (int j = 0; j < N; j++)
			arr[i][j] = input[j] - '0';
	}

	divide(0, 0, N);
}