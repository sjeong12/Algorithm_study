#include <stdio.h>

void sort_arr(int *arr)
{
	int temp;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main(void)
{
	int arr[3];

	while (1)
	{
		scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
		sort_arr(arr);
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			break;
		if ((arr[0] * arr[0]) + (arr[1] * arr[1]) == (arr[2] * arr[2]))
			printf("right\n");
		else
			printf("wrong\n");
	}
	return (0);
}