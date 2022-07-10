#include <stdio.h>

bool prime[10001];

void erato_init(void)
{
	prime[0] = true;
	prime[1] = true;
	for (int i = 2; i <= 10000; i++)
	{
		if (prime[i])
			continue;
		for (int j = i * 2; j <= 10000; j += i)
			prime[j] = true;
	}
}

int main(void)
{
	int T, n;
	int num1, num2;

	scanf("%d", &T);
	erato_init();
	while (T--)
	{
		scanf("%d", &n);
		for (num1 = n / 2; num1 > 1; num1--)//중앙에서부터 작은 쪽으로 이동
		{
			if (prime[num1] == true)
				continue;
			for (num2 = n / 2; num2 <= n; num2++)//중앙에서부터 큰 쪽으로 이동
			{
				if (prime[num2] == true)
					continue;
				if (num1 + num2 == n) goto OUT;
			}
		}
		OUT: printf("%d %d\n", num1, num2); 
	}
	return (0);
}