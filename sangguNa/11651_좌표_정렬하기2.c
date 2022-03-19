#include <stdio.h>
#include <stdlib.h>

typedef struct	s_mat
{
	int	x;
	int	y;
}				t_mat;

int compare(const void *a, const void *b)
{
	t_mat	*num1 = (t_mat *)a;
	t_mat	*num2 = (t_mat *)b;

	if (num1->y < num2->y)
		return (-1);
	else if (num1->y > num2->y)
		return (1);
	else
	{
		if (num1->x < num2->x)
			return (-1);
		else
			return (1);
	}
	return (0);
}

int main(void)
{
	t_mat	m[100000];
	int		N;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &m[i].x, &m[i].y);
	
	qsort(m, N, sizeof(t_mat), compare);

	for (int i = 0; i < N; i++)
		printf("%d %d\n", m[i].x, m[i].y);
	
	return (0);
}