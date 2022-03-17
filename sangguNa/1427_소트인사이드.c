#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long	determin(int n)
{
	long long	temp;

	if (n < 0)
		temp = -(long long)n;
	else
		temp = (long long)n;
	return ((long long)temp);
}

int	get_len_int(int n)
{
	int			len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*my_itoa(int n)
{
	int			s_len;
	int			check;
	char		*str;
	long long	temp;

	if (n < 0)
		check = -1;
	else
		check = 1;
	s_len = get_len_int(n);
	str = (char *)malloc(sizeof(char) * (s_len + 1));
	if (str == 0)
		return (NULL);
	str[s_len] = 0;
	s_len--;
	temp = determin(n);
	while (s_len >= 0)
	{
		str[s_len] = temp % 10 + '0';
		temp = temp / 10;
		s_len--;
	}
	if (check == -1)
		str[0] = '-';
	return (str);
}

int main(void)
{
	int N, size, step, i;
	char *num;
	char temp;

	scanf("%d", &N);
	num = my_itoa(N);
	size = strlen(num);

	for (step = 0; step < size - 1; step++)
	{
		for (i = 0; i < size - 1 - step; i++)
		{
			if (num[i] < num[i + 1])
			{
				temp = num[i];
				num[i] = num[i + 1];
				num[i + 1] = temp;
			}
		}
	}
	printf("%s\n", num);
	free(num);
	return (0);
}