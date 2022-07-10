#include <iostream>

using namespace std;

int N, r, c;
int ans;

void Z(int y, int x, int size)
{
	if (y == r && x == c)
	{
		cout << ans << '\n';
		return ;
	}
	
	//r, c가 현재 사분면에 존재하면
	if (r < y + size && r >= y && c < x + size && c >= x)
	{
		Z(y, x, size / 2);//1사분면 탐색
		Z(y, x + size / 2, size / 2);//2사분면 탐색
		Z(y + size / 2, x, size / 2);//3사분면 탐색
		Z(y + size / 2, x + size / 2, size / 2);//4사분면 탐색
	}
	else//현재 사분면에 존재하지 않으면 탐색할 필요가 없으므로, 현재 사분면의 크기를 더해줌
		ans += size * size;
}

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> r >> c;
	Z(0, 0, (1 << N));//쉬프트 연산을 이용해서 2 ^ N 표현
	return (0);
}