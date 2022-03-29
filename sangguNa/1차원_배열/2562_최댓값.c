#include <stdio.h>

int main(void)
{
	int max_num = -1;
	int index;
	int arr[9];

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]);
		if (max_num < arr[i])
		{
			max_num = arr[i];
			index = i;
		}
	}

	printf("%d\n%d\n", max_num, index + 1);
}