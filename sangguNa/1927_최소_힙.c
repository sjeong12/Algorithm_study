#include <stdio.h>

int heap[100001], size = 0;//힙은 편의를 위해 0번 인덱스를 사용안함
int N;

void swap(int from, int to)
{
	int temp;

	temp = heap[from];
	heap[from] = heap[to];
	heap[to] = temp;
}

void push(int x)
{
	heap[++size] = x;
	/*
		맨 밑의 노드에서부터 부모노드(index : 1)까지 비교해서
		입력된 숫자를 배치
	*/
	for (int i = size; i > 1; i /= 2)
	{
		if (heap[i] < heap[i / 2])//만약 입력된 노드가 그 부모노드보다 작다면
			swap(i, i / 2);//서로 자리 교체
		else
			break;
	}
}

int pop()
{
	int top;
	int i;

	top = heap[1];//부모노드의 값을 넣음
	heap[1] = heap[size];//가장 아랫노드를 부모노드에 삽입
	heap[size--] = 2147483647; //가장 아랫노드를 부모노드에 삽입했으므로 최댓값을 넣음
	i = 1;
	while (i * 2 <= size)
	{
		//현재 부모노드가 자식노드들(i * 2, i * 2 + 1)보다 작으면 반복문을 멈춤
		if (heap[i] < heap[i * 2] && heap[i] < heap[i * 2 + 1])
			break;
		else if (heap[i * 2] < heap[i * 2 + 1])//왼쪽 자식노드가 작다면
		{
			swap(i, i * 2);//왼쪽과 교체
			i = i * 2;
		}
		else
		{
			swap(i, i * 2 + 1);//반대로 오른쪽이 작다면 오른쪽과 교체
			i = i * 2 + 1;
		}
	}
	return (top);
}

int main(void)
{
	int x;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &x);
		if (x == 0)
		{
			if (size == 0)
				printf("0\n");
			else
				printf("%d\n", pop());
		}
		else
			push(x);
	}
	
	return (0);
}