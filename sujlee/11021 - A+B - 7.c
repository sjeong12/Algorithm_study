#include <stdio.h>

int	main()
{
	int	t, a, b, num;

	scanf("%d", &t);
	num = 0;
	while (++num <= t)
	{
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n", num, a + b);
	}
	return (0);
}