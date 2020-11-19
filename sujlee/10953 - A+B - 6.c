#include <stdio.h>

int	main()
{
	int	t, a, b;

	scanf("%d", &t);
	while(--t >= 0)		//t번 a,b를 입력받아 +연산
	{
		scanf("%d,%d", &a, &b);
		printf("%d\n", a + b);
	}
	return (0);
}