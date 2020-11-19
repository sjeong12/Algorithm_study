#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;

int	main()
{
	int	n, num[10000];	// 1 <= n <= 10000;
	int i, j;	//순열 index
	int	tmp; //swap용

	//입력
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &num[i]);
	//풀이
	for (i = n - 1; i > 0; i--)
		if (num[i - 1] > num[i]) //뒤에서부터 내림차순이 아니게 되는 지점(i-1) 찾기
		{
			for (j = n - 1; j > i - 1; j--)	//그 지점(i-1)의 수보다 작은 수를 뒤에서 찾아 swap
				if (num[i - 1] > num[j])
					break;
			tmp = num[j];
			num[j] = num[i - 1];
			num[i - 1] = tmp;
			break;
		}
	//출력
	if (i == 0)
	{
		printf("-1");
		return (0);
	}
	sort(num + i, num + n, greater<int>()); //그 지점(i-1) 이후의 숫자들을 내림차순 정렬
	for (i = 0; i < n; i++)
		printf("%d ", num[i]);
	return (0);
}