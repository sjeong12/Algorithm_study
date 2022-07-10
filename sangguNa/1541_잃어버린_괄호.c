#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	str[51];
int		arr[25] = {0};
int		s_len = 0;
int 	cnt = 0, temp = 0, sum = 0, result = 0;

int main(void)
{
	scanf("%s", str);

	s_len = strlen(str);//총 문자열 길이

	for (int i = 0; i <= s_len; i++)
	{
		if (str[i] == '-' || i == s_len)//'-' 문자를 만났을 경우
		{
			sum = sum + temp;//이전까지의 숫자들을 sum에 더하고
			arr[cnt] = sum;//더한 수들을 저장하기 위해 arr에 넣음
			cnt++;
			temp = 0;//임시저장 및 합 초기화
			sum = 0;
		}
		else if (str[i] == '+')//'+' 문자를 만났을 경우
		{
			sum = sum + temp;//계산한 수들을 sum에 더함
			temp = 0;//임시 저장 초기화
		}
		else//일반 숫자를 만난 경우
		{
			temp = temp * 10;
			temp = temp + str[i] - '0';//문자열을 숫자로 바꿔서 계산
		}
	}

	result = arr[0];
	for (int i = 1; i < cnt; i++)
		result = result - arr[i];

	printf("%d\n", result);
}