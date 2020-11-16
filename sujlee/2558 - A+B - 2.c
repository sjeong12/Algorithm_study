#include <stdio.h>

int	main ()
{
	int a, b;

	scanf("%d\n%d", &a, &b);	//a와 b를 개행문자로 구분하여 입력받음
	printf("%d", a + b);
	return (0);
}