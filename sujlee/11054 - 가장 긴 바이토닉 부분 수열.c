#include <stdio.h>

int	main()
{
	int	n, a[1000];
	int	max = 0, dp_left[1000], dp_right[1000];

	//입력
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	//풀이
	//증가하는 순열
	dp_left[0] = 1;
	for(int now = 1; now < n; now++)
	{
		dp_left[now] = 1;
		for (int left = 0; left < now; left++)
		{
			if (a[left] < a[now]) //왼쪽에 더 작은 수가 있으면, 그 위치의 dp에 + 1
				if (dp_left[now] < dp_left[left] + 1)
					dp_left[now] = dp_left[left] + 1; //그 중에서도 max값을 고름
		}
	}
	//감소하는 순열 (거꾸로 구함)
	dp_right[n - 1] = 1;
	for(int now = n - 2; now >= 0; now--)
	{
		dp_right[now] = 1;
		for (int right = n - 1; right > now; right--)
		{
			if (a[now] > a[right]) //오른쪽에 더 작은 수가 있으면, 그 위치의 dp에 + 1
				if (dp_right[now] < dp_right[right] + 1)
					dp_right[now] = dp_right[right] + 1; //그 중에서도 max값을 고름
		}
	}
	//두 순열을 합친 값 중 max를 구함
	for (int i = 0; i < n; i++)
		if (max < dp_left[i] + dp_right[i] - 1)
			max = dp_left[i] + dp_right[i] - 1; //i번째 수는 두 순열에 모두 포함되기 때문에 -1 처리
	printf("%d\n", max);
	return (0);
}