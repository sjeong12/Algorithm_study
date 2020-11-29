#include <stdio.h>
#include <stdlib.h>

// n, num = 입력값
// check = 배열 num을 순회하면서, 이미 방문한 곳은 1로 체크
// mix = num을 mix하여 순서를 바꾼 순열
// max_num = 출력할 max 값
int	n, num[8], check[8], mix[8], max_num;

//num으로 만들 수 있는 모든 경우의 순열을 생성하고, 그 연산값을 max와 비교
void	mix_num(int mix_i)
{
	int res, i;	//res = 완성된 mix 순열의 연산값

	if (mix_i == n)
	{
		res = 0;
		for (i = 0; i < n - 1; i++)		//문제에서 제시한 공식
			res += abs(mix[i] - mix[i + 1]);
		if (max_num < res)		//max 갱신
			max_num = res;
		return ;
	}
	for (i = 0; i < n; i++)
		if (check[i] != 1)
		{
			mix[mix_i] = num[i];
			check[i] = 1;
			mix_num(mix_i + 1);
			check[i] = 0;
		}
	return ;
}

int		main()
{
	int	i;

	//입력
	scanf("%d", &n);
	i = -1;
	while (++i < n)
	{
		scanf("%d", &num[i]);
		check[i] = 0; //초기화
	}
	//풀이
	max_num = 0;
	mix_num(0);
	//출력
	printf("%d\n", max_num);
	return (0);
}