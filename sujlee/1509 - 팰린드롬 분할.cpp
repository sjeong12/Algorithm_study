#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;
int	main()
{
	int		len, cnt[2501];	//cnt[a] = ~a문자열의 팰린드롬 개수 최소값
	bool	dp[2501][2501];	//dp[a][b] = str의 a~b문자열이 팰린드롬인가
	char	str[2501];

	//입력
	scanf("%s", str);
	len = strlen(str);
	//풀이 - dp[a][a]와 dp[a][a+1]의 팰린드롬 체크
	for (int i = 0; i < len; i++)
		dp[i][i] = true;
	for (int i = 0; i < len - 1; i++)
		if (str[i] == str[i + 1])
			dp[i][i + 1] = true;
	//그 외 dp[][]의 팰린드롬 체크
	for (int size = 3; size <= len; size++)
		for (int left = 0; left + size <= len; left++)
		{
			int right = left + size - 1;
			//양쪽 끝(left, right)이 같고, 그 사이(left+1 ~ right-1)의 문자열도 팰린드롬인가
			if (str[left] == str[right] && dp[left + 1][right - 1])
				dp[left][right] = true;
		}
	//최소 팰린드롬 개수 구하기
	fill(cnt, cnt + len, 999999);
	cnt[0] = 1;
	for (int end = 1; end < len; end++)
	{
		if (dp[0][end])	//~end == dp[0][end] == cnt[end]
		{
			cnt[end] = 1;
			continue ;
		}
		for (int begin = 0; begin < end; begin++)
			if (dp[begin + 1][end] && cnt[end] > cnt[begin] + 1)
				cnt[end] = cnt[begin] + 1;
	}
    printf("%d\n", cnt[len - 1]);
	return (0);
}