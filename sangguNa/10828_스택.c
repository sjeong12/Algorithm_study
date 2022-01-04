#include <stdio.h>
#include <string.h>

int number[10001];
int count = 0;

void push(int num)
{
	number[count] = num;
	count++;
}

void pop()
{
	if (count != 0)
	{
		count--;
		printf("%d\n", number[count]);
		number[count] = 0;
	}
	else
		printf("-1\n");
}

void top()
{
	if (count != 0)
		printf("%d\n", number[count - 1]);
	else
		printf("-1\n");
}

void size()
{
	printf("%d\n", count);
}

void empty()
{
	if (count != 0)
		printf("0\n");
	else
		printf("1\n");
}

int main(void)
{
	int N;
	int num;
	char command[10];

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", &command);
		
		if (strcmp(command, "push") == 0)
		{
			scanf("%d", &num);
			push(num);
		}
		else if (strcmp(command, "pop") == 0)
			pop();
		else if (strcmp(command, "top") == 0)
			top();
		else if (strcmp(command, "size") == 0)
			size();
		else if (strcmp(command, "empty") == 0)
			empty();
	}
}