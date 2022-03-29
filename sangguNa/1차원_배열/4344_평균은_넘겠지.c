#include <stdio.h>
#include <math.h>

int main(void)
{
	int C, N;
	int score[1000];
	int sum, count;
	float avg1;

	scanf("%d", &C);
	while (C--)
	{
		sum = 0;
		count = 0;
		avg1 = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &score[i]);
			sum += score[i];
		}
		avg1 = sum / N;
		for (int i = 0; i < N; i++)
			if (avg1 < score[i])
				count++;
		printf("%.3f%%\n", (float)count / N * 100);
	}
	return (0);
}