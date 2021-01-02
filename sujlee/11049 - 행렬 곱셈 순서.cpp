#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int	arr[501][2], dp[501][501];		//arr[n][] = n번째로 입력 받은 rc값
int	find_min(int start, int end)	//dp[start][end] = arr를 satrt ~ end까지 곱했을 때 최소값
{
	if (dp[start][end] != pow(2, 31) - 1)	//이미 값을 구한 곳은 패스
		return (dp[start][end]);
	if (start == end)						//같은 행렬은 곱하지 않으므로 0
		return (dp[start][end] = 0);
	if (start + 1 == end)					//서로 인접한 행렬은 곱한다
		return (dp[start][end] = arr[start][0] * arr[start][1] * arr[end][1]);
	for (int mid = start; mid < end; mid++)//쪼갤 수 있는 모든 케이스를 조회
	{
		int left = find_min(start, mid);
		int right = find_min(mid + 1, end);
		dp[start][end] = min(dp[start][end],
		left + right + arr[start][0] * arr[mid][1] * arr[end][1]);
	}
	return (dp[start][end]);
}

int	main()
{
	int n;

	//입력 및 초기화 - dp는 문제에서 제시한 최대 값으로 초기화
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	fill(&dp[0][0], &dp[500][500], pow(2, 31) - 1);
	//풀이 - 파일합치기 참고해보기
	printf("%d\n", find_min(1, n));
	return (0);
}