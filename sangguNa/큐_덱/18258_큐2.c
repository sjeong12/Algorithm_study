#include <stdio.h>
#include <string.h>

typedef struct	s_queue
{
	int			data[2000000];
	int			front;
	int			rear;
}				t_queue;

void init(t_queue *q)
{
	q->front = -1;
	q->rear = -1;
}

int	is_empty(t_queue *q)
{
	return (q->front == q->rear);
}

int	size(t_queue *q)
{
	if (is_empty(q))
		return (0);
	return (q->rear - q->front);
}

void push(t_queue *q, int data)
{
	q->data[++(q->rear)] = data;
}

int pop(t_queue *q)
{
	if (is_empty(q))
		 return (-1);
	return (q->data[++(q->front)]);
}

int front(t_queue *q)
{
	if (is_empty(q))
		return (-1);
	return (q->data[q->front + 1]);
}

int back(t_queue *q)
{
	if (is_empty(q))
		return (-1);
	return (q->data[q->rear]);
}

int main(void)
{
	t_queue q;
	init(&q);

	int		N;
	int		data;
	scanf("%d", &N);

	while(N--)
	{
		char str[6];
		scanf("%s", &str);

		if (!strcmp(str, "push"))
		{
			data = 0;
			scanf("%d", &data);
			push(&q, data);
		}
		else if (!strcmp(str, "pop"))
			printf("%d\n", pop(&q));
		else if (!strcmp(str, "size"))
			printf("%d\n", size(&q));
		else if (!strcmp(str, "empty"))
			printf("%d\n", is_empty(&q));
		else if (!strcmp(str, "front"))
			printf("%d\n", front(&q));
		else if (!strcmp(str, "back"))
			printf("%d\n", back(&q));
	}
	return (0);
}