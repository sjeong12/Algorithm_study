#include <stdio.h>
#define SIZE 500000

int main(void)
{
	int N;
	int front = 0;//시작점을 가리킴
	int rear;//끝을 가리킴
	int q[SIZE];

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		q[i] = i + 1;//0번째 인덱스부터 1 ~ N까지 채움
	rear = N - 1;

	while (1)
	{
		front = (front + 1) % N;//제일 위의 카드를 버림
		if (front == rear)//만약 f == r이면 1장만 남은 상태이므로 break
			break ;
		rear = (rear + 1) % N;
		q[rear] = q[front];
		//여기까지가 위의 카드를 카드덱 맨 밑에 놓는 과정. 
		//원형 큐이므로 처음 인덱스(rear == 0)으로 가게됨
		front = (front + 1) % N;//다음 인덱스로 옮김
		if (front == rear)
			break ;
	}
	printf("%d\n", q[rear]);//남아있는 1장의 카드 출력
	return (0);
}