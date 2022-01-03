#include <stdio.h>

int main(void)
{
	long long	result = 0;
	int			distance[100000];
	int			N, min, cur;

	scanf("%d", &N);

	for (int i = 0; i < N - 1; i++)
		scanf("%d", &distance[i]);//각 도시간 거리 입력받기
	
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%d", &cur);//각 도시의 리터당 가격을 입력받음
		if (i == 0 || cur < min)//처음 입력받거나 || 현재 입력받은 게 최솟값보다 작다면
			min = cur;//최솟값에 입력받은 값을 저장
		result += (long long)min * distance[i];//최소값과 거리를 곱해 비용을 result에 더함
	}

	printf("%lld\n", result);
	return (0);
}