#include <stdio.h>

int main(void)
{
	float N;
	float arr[1000];
	float max_score = -1;
	float sum = 0;
	float avg = 0;;

	scanf("%f", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%f", &arr[i]);
		if (max_score < arr[i])
			max_score = arr[i];
	}

	for (int i = 0; i < N; i++)
		sum += (arr[i] / max_score) * 100;

	avg = sum / N;
	printf("%f\n", avg);
	return(0);
}