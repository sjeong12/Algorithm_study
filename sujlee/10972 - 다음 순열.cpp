#include <stdio.h>
#include <algorithm>

using namespace std;

int	main()
{
	int	n, nums[10000];
	int	i, j;

	//입력
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &nums[i]);
	//풀이
	for (i = n - 1; i > 0; i--)
	{	//뒤에서부터, 오름차순이 아니게 되는 지점(i - 1)을 찾는다
		if (nums[i - 1] < nums[i])
		{	//i - 1보다 큰 수를 뒤에서부터 찾아 swap
			for (j = n - 1; j >= i; j--)
				if (nums[i - 1] < nums[j])
					break ;
			int tmp = nums[i - 1];
			nums[i - 1] = nums[j];
			nums[j] = tmp;
			break ;
		}
	}
	if (i == 0)	//뒤에서부터 0번지까지 모두 오름차순이었다면, 다음 순열이 없다
	{
		printf("%d", -1);
		return (0);
	}
	sort(nums + i, nums + n);	//i - 1 지점 이후 숫자는, 앞에서부터 오름차순으로 sort한다
	for (int i = 0; i < n; i++)
		printf("%d ", nums[i]);
	return (0);
}
