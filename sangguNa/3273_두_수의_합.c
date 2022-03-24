#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if (num1 < num2)
		return (-1);
	else if (num1 > num2)
		return (1);
	return (0);
}

int main(void)
{
	int *num;
	int N, x, left, right, count, sum;

	scanf("%d", &N);
	num = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);
	scanf("%d", &x);

	count = 0;
	left = 0;
	right = N - 1;
	sum = 0;

	qsort(num, N, sizeof(num[0]), compare);

	while (left < right)
	{
		if (num[left] + num[right] == x)
		{
			count++;
			right--;
		}
		else if (num[left] + num[right] > x)
			right--;
		else
			left++;
	}
	printf("%d\n", count);
	free(num);
	return (0);
}