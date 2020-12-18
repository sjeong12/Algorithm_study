#include <stdio.h>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int		a, b;
int		check[10000];		//방문 여부 + 몇번에 거쳐 숫자를 만들었는지 체크
bool	is_valid[10000];	//소수 여부 체크

//에라토스의 체로 9999까지의 소수를 구함
void	erotos()
{
	memset(is_valid, true, sizeof(is_valid));
	for (int i = 2; i * i <= 9999; i++)
		if (is_valid[i])
			for (int j = i * i; j <= 9999; j += i)
				is_valid[j] = false;
	return ;
}

//bfs로 숫자를 하나씩 바꿔가며, 생성가능한 모든 소수를 검사.
//해당 숫자를 만들기까지 거쳐온 횟수는 check에 저장.
void	bfs(int begin)
{
	queue<int>	nums;			//검사할 숫자들
	int			num, next_num;	//현재 검사할 숫자, 다음 검사 대상
	string		s_num;			//문자열화 한 숫자

	nums.push(begin);
	check[begin] = 0;
	while(!nums.empty())	//큐와 체크배열 초기화 후, 모든 수를 검사하거나 b를 찾을때까지 반복
	{
		num = nums.front();
		nums.pop();
		for (int i = 0; i < 4; i++)		//4개의 숫자를 앞자리부터 하나씩 변경
		{
			s_num = to_string(num);
			for (int j = 0; j < 10; j++)
			{
				s_num[i] = j + '0';
				next_num = 1000 * (s_num[0] - '0') + 100 * (s_num[1] - '0') + 10 * (s_num[2] - '0') + s_num[3] - '0';
				//수가 1000이상이고, 소수이며, 아직 생성한 적이 없었던 수이면 통과
				if (next_num >= 1000 && is_valid[next_num] && check[next_num] == -1)
				{
					check[next_num] = check[num] + 1;	//수를 만들기까지 거쳐온 횟수를 저장
					if (next_num == b)					//b를 찾았을 경우 return
						return ;
					nums.push(next_num);
				}
			}
		}
	}
	return ;
}


int		main()
{
	int	t;

	scanf("%d", &t);
	erotos();	//9999까지의 소수를 구함
	while (t--)
	{
		memset(check, -1, sizeof(check));
		scanf("%d %d", &a, &b);
		bfs(a);		//bfs로 숫자 b가 나올때까지 a를 변형하여 소수를 구함
		if (check[b] == -1)
			printf("Impossible\n");
		else
			printf("%d\n", check[b]);
	}
	return (0);
}