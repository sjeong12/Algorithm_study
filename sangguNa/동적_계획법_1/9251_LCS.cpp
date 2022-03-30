#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int Bigger(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int main(void)
{
	char 	str1[1001];
	char 	str2[1001];
	int		dp[1001][1001];
	int		s1_len, s2_len;

	cin >> str1;
	cin >> str2;
	s1_len = strlen(str1);
	s2_len = strlen(str2);

	for (int i = 1; i <= s1_len; i++)
	{
		for (int j = 1; j <= s2_len; j++)
		{
			if (str1[i - 1] == str2[j - 1])//비교 문자가 동일하면
				dp[i][j] = dp[i - 1][j - 1] + 1;//이전까지의 LCS 에 +1을 해줌
			else//비교 문자가 다르다면
				dp[i][j] = Bigger(dp[i - 1][j], dp[i][j - 1]);//이전까지의 LCS에서 각각의 문자를 넣었을 때, 더 큰값으로 LCS값을 갱신
		}
	}

	cout << dp[s1_len][s2_len] << endl;
}