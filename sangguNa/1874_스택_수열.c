#include <stdio.h>
#include <string.h>
#define SIZE 100000

char	result[SIZE * 2];//하나의 숫자에 +,- 가 붙으므로 2배
int		stack[SIZE];//1 ~ N을 담는 스택
int		input[SIZE];//입력값을 받는 배열
int		top = -1;

int main(void)
{
	int	N;
	int	num;
	int	idx, result_idx;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &input[i]);
	
	num = 1;//스택에 1부터 넣기 시작
	idx = 0;//입력값을 넣은 스택의 index
	result_idx = 0;//+, -를 집어넣는 배열의 index

	while (1)
	{
		//스택에 있는 수가 목표 수보다 낮은 경우 push(+)
		if (top == -1 || stack[top] < input[idx])
		{
			stack[++top] = num++;
			result[result_idx++] = '+';
		}
		//스택 상단에 있는 수가 목표 수와 동일하면 pop(-)
		else if (stack[top] == input[idx])
		{
			top--;
			result[result_idx++] = '-';
			idx++;
		}
		//스택 상단에 있는 수가 목표 수보다 높은 경우(스택 상단 : 4, 목표수 : 3)
		//원하는 수열을 만들 수 없으므로 NO 출력
		else
		{
			printf("NO\n");
			return (0);
		}
		if (result_idx == N * 2)
			break ;
	}
	for (int i = 0; i < result_idx; i++)
		printf("%c\n", result[i]);
	
	return (0);
}