#include <stdio.h>

int	main()
{
	char	str[101];

	//입력
	scanf("%s", (char *)&str);
	//출력
	for (int i = 0; str[i] != 0; i++)
	{
		printf("%c", str[i]);
		if (i % 10 == 9) //10단위 마다 \n문자 출력
			printf("\n");
	}
	return (0);
}