#include <stdio.h>
#include <stdlib.h>

typedef struct	s_sign
{
	int		age;
	char	name[101];
	int		order;
}				t_sign;

int compare(const void *a, const void *b)
{
	t_sign *s1 = (t_sign *)a;
	t_sign *s2 = (t_sign *)b;

	if (s1->age < s2->age)
		return (-1);
	else if (s1->age > s2->age)
		return (1);
	else
	{
		if (s1->order < s2->order)
			return (-1);
		else
			return (1);
	}
	return (0);
}

int main(void)
{
	int 	N;
	t_sign	*sign;

	scanf("%d", &N);
	sign = (t_sign *)malloc(sizeof(t_sign) * N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %s", &sign[i].age, &sign[i].name);
		sign[i].order = i;
	}

	qsort(sign, N, sizeof(sign[0]), compare);

	for (int i = 0; i < N; i++)
		printf("%d %s\n", sign[i].age, sign[i].name);
	
	free(sign);
	return (0);
}