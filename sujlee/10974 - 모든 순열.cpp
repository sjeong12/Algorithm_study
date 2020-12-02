#include <algorithm>
#include <stdio.h>

using namespace std;
int	main()
{
	int	n, num[8], i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		num[i] = i + 1;
	do {
		for (i = 0; i < n; i ++)
			printf("%d ", num[i]);
		printf("\n");
	} while (next_permutation(num, num + n));
	return(0);
}