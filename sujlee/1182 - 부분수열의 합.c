#include <stdio.h>

int n, s, nums[20], cnt = 0;

//sum == s가 되는 모든 경우의 수를 찾아 cnt에 저장
void	find_s(int index, int sum)
{
	if (index >= n)			//n보다 작은 인덱스만 참조
		return ;
	sum += nums[index];		//sum이 s와 같은지 체크
	if (sum == s)
		cnt++;
	//sum에 현재 값을 '더할 경우/더하지 않을 경우'로 나눠 모두 조회
	find_s(index + 1, sum);
	find_s(index + 1, sum - nums[index]);
	return ;
}

int		main()
{
	//입력
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++)
		scanf("%d", &nums[i]);
	//풀이
	find_s(0, 0);
	printf("%d\n", cnt);
	return (0);
}