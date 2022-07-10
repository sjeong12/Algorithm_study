#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<long long>> Mat;
const int MOD = 1000000007;
long long n;
Mat init = {{1, 1}, {1, 0}};

Mat Mat_calculate(Mat a, Mat b)
{
	Mat res(2);
	for (int i = 0; i < 2; i++)
	{
		res[i].resize(2);
		for (int j = 0; j < 2; j++)
		{
			res[i][j] = 0;
			for (int k = 0; k < 2; k++)
			{
				res[i][j] += a[i][k] * b[k][j];
				res[i][k] %= MOD;
			}
		}
	}
	return (res);
}

Mat func(long long n)
{
	if (n == 1)
		return (init);
	Mat tmp;
	if (n % 2)//n이 홀수
	{
		tmp = func(n - 1);//재귀함수 리턴값 저장
		return Mat_calculate(init, tmp);
	}
	else//n이 짝수
	{
		tmp = func(n / 2);
		return Mat_calculate(tmp, tmp);
	}
}

int main(void)
{
	cin >> n;
	if (n == 0)
	{
		cout << 0 << "\n";
		return (0);
	}
	Mat res = func(n);
	cout << res[1][0] << "\n";
}