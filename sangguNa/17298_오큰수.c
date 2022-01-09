#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int			N;
int			*arr;
int			*ans;

typedef struct	s_stack
{
	int		*stack;
	int		size;
}				t_stack;

void push(t_stack *s, int a)
{
	s->stack[s->size++] = a;
}

int pop(t_stack *s)
{
	return (s->stack[--s->size]);
}

int top(t_stack *s)
{
	return (s->stack[s->size - 1]);
}

int isEmpty(t_stack *s)
{
	return (s->size == 0);
}

int main(void)
{
	t_stack		s;

	scanf("%d", &N);
	s.stack = (int *)calloc(N, sizeof(int));
	s.size = 0;
	arr = (int *)calloc(N, sizeof(int));
	ans = (int *)calloc(N, sizeof(int));

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		ans[i] = -1;
	}

	for (int i = 0; i < N; i++)
	{
		while (!isEmpty(&s) && arr[top(&s)] < arr[i])
			ans[pop(&s)] = arr[i];
		push(&s, i);
	}

	for (int i = 0; i < N; i++)
		printf("%d ", ans[i]);

	free(arr);
	free(ans);
}