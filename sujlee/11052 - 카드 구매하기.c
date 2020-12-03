#include <stdio.h>

int	main()
{	//dp[a] = b; 카드를 a장 샀을 때 가장 높은 비용 = b라는 의미
	int 	n, p[10001], dp[10001], price;

	//입력
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	//풀이 - now : 현재 기준이 되는 카드팩 번호, before : 그보다 작은 카드팩 번호
	dp[1] = p[1];
	for (int now = 2; now <= n; now++)
	{
		dp[now] = p[now];								//now번째 dp를 now장짜리 카드팩으로 초기화
		for (int before = 1; before < now; before++)	//now장 이하의 카드팩(before)끼리 조합해본다
		{
			price = dp[now - before] + dp[before];		//now가 4라면? 4, 3+1, 2+2, 1+3의 조합을 체크
			if (price > dp[now])						//그 중 max값을 dp에 저장
				dp[now] = price;
		}
	}
	printf("%d\n", dp[n]);
	return (0);
}

/*	예제는 맞았으나 채점시 틀림. 틀린 예제가 무엇일까?
int	main()
{
	//max_i = 가장 비싼 카드, cnt = 개당 카드 개수, sum_c/p = 총 카드 개수/가격
	//price[] = 카드 1개당 가격
	int 	n, p[10001];
	int		max_i = 0, cnt = 0, sum_c = 0, sum_p = 0;
	float	price[10001];

	//입력
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	//풀이
	//카드 1개당 가격으로 환산
	for (int i = 1; i <= n; i++)
		price[i] = (float)p[i] / (float)i;
	//환산 가격이 가장 비싼 카드(max_i) 순으로 구매
	while (sum_c < n)
	{
		max_i = 1;
		for (int i = 2; i <= n; i++)
			if (sum_c + i <= n &&		//카드 개수(sum_c)가 n보다 작거나 같아야 한다
			price[max_i] < price[i])	//환산한 price 중 max를 찾는다
				max_i = i;
		//max_i번째 카드를 cnt개수만큼 구매
		cnt = (n - sum_c) / max_i;
		sum_c += max_i * cnt;
		sum_p += p[max_i] * cnt;
		price[max_i] = -1;				//이미 구매한 카드를 제외하고 반복
	}
	printf("%d\n", sum_p);
	return(0);
}
*/