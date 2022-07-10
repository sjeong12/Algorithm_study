#include <iostream>

#define endl	"\n"
#define MAX		130
using namespace	std;

int N, blue, white;
int map[MAX][MAX];

void input(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
}

void dfs(int x, int y, int size)
{
	bool zero, one;//0은 하양, 1은 파랑
	zero = one = true;

	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (map[i][j] == 1)//만약 탐색하는 맵이 1이라면
				zero = false;//하양이 아니라고 알림
			if (map[i][j] == 0)//반대로 0이면
				one = false;//파랑이 아니라고 알림 
		}
	}

	if (zero == true)//탐색을 다 할때까지 zero가 true상태면
	{
		white++;//하얀 색종이만 있단 뜻이므로 갯수 증가
		return ;
	}
	if (one == true)//반대의 경우
	{
		blue++;
		return ;
	}

	//둘다 false 인 경우 색상이 완전히 나눠진 게 아니므로 재귀(DFS) 실행
	//현재 사이즈를 절반으로 나눠서, 4부분을 탐색
	dfs(x, y, size / 2);
	dfs(x, y + size / 2, size / 2);
	dfs(x + size / 2, y, size / 2);
	dfs(x + size / 2, y + size / 2, size / 2);
}

int main(void)
{
	input();
	dfs(0, 0, N);

	cout << white << endl << blue << endl;
}