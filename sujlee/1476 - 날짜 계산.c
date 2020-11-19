#include <stdio.h>

//year -> esm 환산
int	year_to_esm(int year, int base)
{
	int esm;	//return 값

	esm = year;
	while (esm >= base)
	{
		esm = 0;
		esm += year % base;
		esm += year / base;	//이 때 값이 base보다 클 경우 반복해야함
		year = esm;
	}
	return (esm);
}

int	main()
{
	int E, S, M, year = 1;		//입력 ESM, 출력 year

	//입력
	scanf("%d %d %d", &E, &S, &M);
	//풀이 - year를 1씩 증가시키며, esm연도로 환산(year_to_esm)하여 비교
	while (1)
	{
		if (year_to_esm(year, 16) == E &&
		year_to_esm(year, 29) == S &&
		year_to_esm(year, 20) == M)
			break;
		year++;
	}
	//출력
	printf("%d", year);
	return (0);
}