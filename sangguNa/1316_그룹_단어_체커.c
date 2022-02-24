#include <stdio.h>
#include <string.h>

void init(int *check)
{
	for (int i = 0; i < 26; i++)
		check[i] = 0;
}

int main(void)
{
	char input[101];
	int check[26];
	int N, len, count;

	scanf("%d", &N);
	count = N;
	while (N--)
	{
		init(check);
		scanf("%s", &input);
		len = strlen(input);
		char first = '0';
		int i = 0;
		while (i < len)
		{	
			if (first != input[i])//새 단어를 만났을 때
			{
				first = input[i];//단어 저장
				check[input[i] - 'a'] += 1;//새 단어 만났다고 카운트
			}
			if (check[input[i] - 'a'] == 2)//만약 2이상이면 서로 떨어진 동일단어
			{
				count -= 1;//그룹단어 갯수 -1
				break;
			}
			i++;
		}
	}
	printf("%d\n", count);
	return (0);
}