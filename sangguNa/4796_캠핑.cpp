#include <iostream>

using namespace std;

int main(void)
{
	int i = 0;
	int l, p, v, ans;
	/*
	** l:사용가능한 일 수, p:캠핑장의 연속 일 수, v:휴가 일 수
	*/
	while (true)
	{
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0)
			break;
		ans = min(v % p, l) + (v / p) * l;
		cout << "Case " << ++i << ": " << ans << '\n';
	}
	return (0);
}