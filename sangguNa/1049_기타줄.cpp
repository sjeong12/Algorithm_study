#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, m, p, s;
	int package = 1000, single = 1000;

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> p >> s;
		package = min(package, p);
		single = min(single, s);
	}
	/*
		1) 가격이 가장 저렴한 브랜드 package 를 구매하고, 남은 낱개는 낱개의 가격이 가장 저렴한 브랜드에서 고르는 경우, (N / 6) x package + (N % 6) x single
		2) 낱개의 가격이 가장 저렴한 브랜드에서 single로만 구매하는 경우, N x single
		3) 세트의 가격이 가장 저렴한 브랜드에서 package 구매하는 경우, (N / 6 + 1) x package
	*/
	cout << min((n / 6 + 1) * package, min(n * single, (n / 6) * package + (n % 6) * single)) << '\n';
	return (0);
}