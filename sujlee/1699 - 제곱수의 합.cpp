#include <stdio.h>
#include <algorithm>

using namespace std;

int	main()
{
	int n, dp[100001] = {0, };	//dp[n] = 숫자 n을 이루는 최소 제곱수 항 개수

	//입력
	scanf("%d", &n);
	//풀이 - dp[num - less * less] + 1 == num보다 작은 제곱수 less^2를 이용하여 num을 만든다
	//less^2항이 추가되었기 때문에, 해당 dp의 개수에 + 1을 해주어야한다.
	for (int num = 1; num <= n; num++)
	{
		dp[num] = num;
		for (int less = 1; less * less <= num; less++)
			dp[num] = min(dp[num], dp[num - less * less] + 1);
	}
	printf("%d\n", dp[n]);
	return (0);
}