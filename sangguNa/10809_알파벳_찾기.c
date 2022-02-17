#include <stdio.h>
#include <string.h>

void init(int *alpha)
{
	for (int i = 0; i < 26; i++)
		alpha[i] = -1;
}

int main(void)
{
	int alpha[26];
	char input[100];
	int change;
	
	init(alpha);

	scanf("%s", &input);
	for (int i = 0; i < strlen(input); i++)
	{
		change = input[i] - 'a';
		if (alpha[change] == -1)
			alpha[change] = i;
	}
	for (int i = 0; i < 26; i++)
		printf("%d ", alpha[i]);
	printf("\n");

	return (0);
}