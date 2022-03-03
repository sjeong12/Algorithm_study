#include <stdio.h>

bool prime[246913];

void erato_init(void)
{
	prime[0] = true;
	prime[1] = true;
	for (int i = 2; i <= 246913; i++)
	{
		if (prime[i])
			continue;
		for (int j = 2 * i; j <= 246913; j += i)
			prime[j] = true;
	}
}

int main(void)
{
	int n, count;

	erato_init();
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		count = 0;
		for (int i = n + 1; i <= 2 * n; i++)
		{
			if (!prime[i])
				count++;
		}
		printf("%d\n", count);
	}
	return (0);
}