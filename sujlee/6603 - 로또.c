#include <stdio.h>

int	k = -1, s[49], lotto[6];

//pos = lotto배열의 인덱스, start = s배열의 start인덱스 이후 숫자들이 lotto에 포함된다
void	make_lotto(int pos, int start)
{
	if (pos == 6)	//6개의 로또 번호를 뽑았으면 출력
	{
		for (int i = 0; i < 6; i ++)
			printf ("%d ", lotto[i]);
		printf ("\n");
		return ;
	}
	for (int i = start; i < k; i++)
	{
		lotto[pos] = s[i];
		make_lotto(pos + 1, i + 1);
	}
	return ;
}

int		main()
{
	//입력
	while ( k != 0)
	{
		scanf("%d", &k);
		for (int i = 0; i < k; i++)
			scanf("%d", &s[i]);
		//풀이
		make_lotto(0, 0);
		printf("\n");
	}
	return (0);
}