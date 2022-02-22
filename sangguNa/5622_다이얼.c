#include <stdio.h>
#include <string.h>

int c_to_num(int i)
{
	switch (i)
	{
	case 'A':
	case 'B':
	case 'C':
		return (3);
	case 'D':
	case 'E':
	case 'F':
		return (4);
	case 'G':
	case 'H':
	case 'I':
		return (5);
	case 'J':
	case 'K':
	case 'L':
		return (6);	
	case 'M':
	case 'N':
	case 'O':
		return (7);
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
		return (8);
	case 'T':
	case 'U':
	case 'V':
		return (9);
	default:
		return (10);
	}
}

int main(void)
{
	char dial[15];
	int time, len;

	scanf("%s", &dial);
	time = 0;
	len = strlen(dial);

	for (int i = 'A'; i <= 'Z'; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (i == dial[j])
				time += c_to_num(i);
		}
	}
	printf("%d\n", time);
	return (0);
}