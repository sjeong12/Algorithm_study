#include <stdio.h>
#include <string.h>

int main(void)
{
	char	str[1000000];
	int		count[26] = {0, };
	int		temp, temp2, len, select, max;
	int		result = 0;
	
	scanf("%s", &str);
	len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			temp = str[i] - 'a';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			temp = str[i] - 'A';
		count[temp] += 1;
	}

	max = 0;
	for (int i = 0; i < 26; i++)
	{
		if (max < count[i])
		{
			max = count[i];
			select = i;
		}
	}

	for (int i = 0; i < 26; i++)
		if (max == count[i])
			result++;
	
	if (result > 1)
		printf("?\n");
	else
		printf("%c\n", select + 'A');
	
	return (0);
}