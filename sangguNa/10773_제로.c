#include <stdio.h>

int stack[100001];
int K;
int count = 0;//스택의 위치를 알기위한 변수
int result = 0;//스택에 남은 수들의 합

int main(void)
{
	int input;

	scanf("%d", &K);

	for (int i = 0; i < K; i++)
	{
		scanf("%d", &input);

		if (input == 0)//0이 들어오면 이전에 입력받은 수 제거
		{
			count--;//count 변수를 먼저 내려야 이전 값의 위치로 옮길 수 있음
			stack[count] = 0;
		}
		else
		{
			stack[count] = input;//그 외엔 입력값을 넣고 count(스택위치) 증가
			count++;
		}
	}

	for (int i = 0; i < count; i++)
		result += stack[i];
	
	printf("%d\n", result);
	return (0);
}