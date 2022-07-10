#include <stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);
	for (int i = 2; i <= N; i++)
	{
		while (N % i == 0)
		{
			printf("%d\n", i);
			N = N / i;
		}
	}
	return (0);
}


/* 실패한 코드
#include <stdio.h>
#include <math.h>

int erato_arr[10000001] = {0, };
int prime[10000001] = {0, };

void erato_init(void)
{
	int sqrt_num = sqrt((float)10000000);
	for (int i = 1; i <= sqrt_num; i++)
	{
		for (int j = 1; j <= sqrt_num; j++)
		{
			if (i * j > sqrt_num)
				break ;
			else
				erato_arr[i * j] += 1;
		}
	}

	int i = 1;
	int idx = 0;
	while (i <= sqrt_num)
	{
		if (erato_arr[i] == 2)
		{
			prime[idx] = i;
			idx++;
		}
		i++;
	}
}

int main(void)
{
	int N;
	int i = 0;

	erato_init();
	scanf("%d", &N);
	if (N == 1)
		return (0);
	while (N > 1)
	{
		if (N % prime[i] == 0)
		{
			printf("%d\n", prime[i]);
			N = N / prime[i];
		}
		else
			i++;
	}
	return (0);
}
*/