#include <stdio.h>

int T;
char str[51];
int count;
int status;

int main(void)
{
	int i, j;

	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		scanf("%s", &str);

		j = 0;
		count = 0;
		status = 0;
		while (str[j])
		{
			if (str[j] == '(')
				count++;
			else if (str[j] == ')')
			{
				count--;
				if (count < 0)//만약 count 가 음수이면 괄호 짝이 안맞으므로
					status = 1;//status에 비정상이라고 알리기 위해 1을 넣음 
			}
			j++;
		}
		if (count == 0 && status == 0)
			printf("YES\n");
		else if (count != 0 || status == 1)//())(() 과 같은 경우도 있으므로 or 문 사용
			printf("NO\n");
	}

	return (0);
}