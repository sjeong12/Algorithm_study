#include <iostream>
#include <algorithm>

using namespace std;

typedef struct  s_arr
{
	int		x;
	int		y;
}			t_arr;

int			N;
t_arr		arr[100000];
int			cur = 0, cnt = 0;

bool compare(t_arr const &a, t_arr const &b)
{
	if (a.y == b.y)//종료 시간이 동일하면
		return a.x < b.x;//시작시간이 작은 수를 오름차순
	return a.y < b.y;//오름차순 정렬
}

int main(void)
{
	int		x, y;
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		cin >> y;
		arr[i] = {x, y};
	}

	sort(arr, arr + N, compare);

	for (int i = 0; i < N; i++)
	{
		if (i == 0)//처음 원소면 카운트 증가, 끝나는 시간 저장
		{
			cnt++;
			cur = arr[i].y;
		}
		else
		{
			if (arr[i].x >= cur)//이전 회의의 끝나는 시간과 비교해 조건 맞으면 카운트 증가
			{
				cnt++;
				cur = arr[i].y;
			}
		}
	}

	cout << cnt << endl;
}