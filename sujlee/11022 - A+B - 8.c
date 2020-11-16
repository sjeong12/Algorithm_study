#include <stdio.h>

int	main()
{
	int n, a, b, cnt = 1;	//cnt는 case 번호

	scanf("%d", &n);
	while (--n >= 0)	//n번만큼 입출력 반복
	{
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d + %d = %d\n", cnt++, a, b, a + b);
	}
	return (0);
}