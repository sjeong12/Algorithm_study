#include <stdio.h>
#include <stdlib.h>

int binary_tree(int *arr, int key, int size)
{
	int front, rear, pivot;

	front = 0;
	rear = size - 1;

	while (1)
	{
		pivot = (front + rear) / 2;
		if (arr[pivot] == key)
			return (1);
		if (arr[front] == key)
			return (1);
		if (arr[rear] == key)
			return (1);

		if (arr[pivot] < key)
			front = pivot + 1;
		else
			rear = pivot - 1;
		
		if (front >= rear)
			return (0);
	}
	
}

int compare(const void *a, const void *b)
{
	return *(int *)a > *(int *)b ? 1 : (*(int *)a < *(int *)b ? -1 : 0);
}

int main(void)
{
	int N, M;
	int arr_N[100000];
	int arr_M[100000];

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr_N[i]);
	
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
		scanf("%d", &arr_M[i]);

	//이진 트리를 사용하기 위해선 먼저 배열이 정렬되있어야하므로
	//stdlib.h의 qsort 함수를 사용함, compare은 비교해주는 함수
	qsort(arr_N, N, sizeof(int), compare);

	for (int i = 0; i < M; i++)
		printf("%d\n", binary_tree(arr_N, arr_M[i], N));

	return (0);
}