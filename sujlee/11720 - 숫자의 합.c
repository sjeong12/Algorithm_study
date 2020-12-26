#include <stdio.h>

int	main()
{
	int n, sum = 0;
	char num[100];

	//입력
	scanf("%d\n%s", &n, &num);
	//풀이 - 문자열로 입력받은 num을 int화 하여 연산
	while(--n >= 0)
		sum += num[n] - '0';
	printf("%d", sum);
	return (0);
}