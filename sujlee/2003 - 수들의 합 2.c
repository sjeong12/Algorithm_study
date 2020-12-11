#include <stdio.h>

int	main()
{
	int	n, m, a[10000], sum, res = 0;

	//입력
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	//풀이 - 부분수열의 시작점 begin을 1씩 증가시키며 합산 sum을 구한다
	for (int begin = 0; begin < n; begin++)
	{
		sum = 0;
		for (int i = begin; sum < m; i++) //sum이 구하고자하는 수보다 작을때까지만 합산
			sum += a[i];
		if (sum == m) //m과 일치하는지 체크
			res++;
	}
	printf("%d", res);
	return (0);
}