#include <stdio.h>

int	main()
{
	int	n, tile[1000], i;

	scanf("%d", &n);
	tile[0] = 1;	//1가지 경우 가능(1x2)
	tile[1] = 3;	//3가지 경우 가능(2x2/1x2 2개/2x1 2개)
	//풀이 - [i - 1]에 1x2 타일 붙이는 케이스 1개. (= tile[i - 1])
	//[i - 2]에 2x1과 2x2를 붙이는 케이스 2개. (= tile[i - 2] * 2)
	i = 1;
	while (++i < n)
		tile[i] = (tile[i - 2] * 2 + tile[i - 1]) % 10007;	//여기서 %10007해야한다
	printf("%d\n", tile[n - 1]);	//tile[n-1] % 10007을 출력하도록 하면 오답. 이유가 뭘까
	return (0);
}