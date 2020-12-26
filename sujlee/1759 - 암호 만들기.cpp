#include <stdio.h>
#include <algorithm>

using namespace std;
int		l, c, is_vowel[26] = {0, };	//is_vowel = 모음 체크용
char	str[15], passward[15];		//passward = 출력할 비밀번호

//now=str에 사용할 시작 인덱스, cnt=passward의 현재 인덱스, vowel=모음개수
void	print_passward(int now, int cnt, int vowel)
{
	if (cnt == l)	//l길이의 비밀번호를 완성
	{
		if (vowel >= 1 && l - vowel >= 2)	//모음이 1이상 자음이 2이상
			printf("%s\n", passward);
		return ;
	}
	for (int i = now; i < c; i++)	//비밀번호는 오름차순이기 때문에, now 보다 큰 문자만 순회
	{
		passward[cnt] = str[i];
		print_passward(i + 1, cnt + 1, vowel + is_vowel[str[i] - 'a']);
	}
	return ;
}

int		main()
{
	//입력 및 초기화 - 모음일 경우 is_vowel을 1로 체크
	scanf("%d %d", &l, &c);
	for (int i = 0; i < c; i++)
	{
		scanf(" %c", &str[i]);
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
			is_vowel[str[i] - 'a'] = 1;
	}
	//오름차순으로 정렬 후, print_passward에서 dfs
	sort(str, str + c);
	print_passward(0, 0, 0);
	return (0);
}