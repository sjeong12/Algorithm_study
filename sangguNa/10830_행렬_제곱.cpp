#include <iostream>

using namespace std;

int mat[5][5];
int temp[5][5];
int res[5][5];
long long N, B;

void pow_mat(int m1[5][5], int m2[5][5])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			temp[i][j] = 0;
			for (int k = 0; k < N; k++)
				temp[i][j] += (m1[i][k] * m2[k][j]);
			temp[i][j] %= 1000;
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			m1[i][j] = temp[i][j];
}

int main(void)
{
	cin >> N >> B;
	for (int i = 0; i < N; i++)
	{	for (int j = 0; j < N; j++)
			cin >> mat[i][j];
		res[i][i] = 1;//단위 행렬 생성
	}
	
	while (B)
	{
		if (B % 2 == 1)//홀수 인 경우
			pow_mat(res, mat);
		pow_mat(mat, mat);
		B /= 2;
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << res[i][j] << ' ';
		cout << "\n";
	}
	
	return (0);
}