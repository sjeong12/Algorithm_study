#include <stdio.h>

int fibo(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (fibo(n - 2) + fibo(n - 1));
}

int main(void)
{
	int N, answer;
	
	scanf("%d", &N);
	answer = fibo(N);
	printf("%d\n", answer);
	return (0);
}