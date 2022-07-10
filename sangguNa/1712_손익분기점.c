#include <stdio.h>

int main(void)
{
	long long A, B, C;
	long long bep;
	
	scanf("%lld %lld %lld", &A, &B, &C);
	if (B >= C)
	{
		printf("-1\n");
		return (0);
	}
	bep = 0;
	bep = A / (C - B);
	printf("%lld\n", bep + 1);
	return (0);
}