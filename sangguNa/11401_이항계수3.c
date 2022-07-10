#include <stdio.h>

long long N, K, A, B, half;
long long mod = 1000000007;

long long solve(int x)
{
	if (x == 0)
		return (1);
	if (x % 2 == 1)
		return (B * solve(x - 1) % mod);
	else
	{
		half = solve(x / 2);
		return (half * half % mod);
	}
}

int main(void)
{
	scanf("%d %d", &N, &K);

	/*
		분수의 형태로는 mod 연산을 할 수 없음
		(N / K) % mod != (N % mod) / (K % mod)
		페르마의 소정리에 따르면, A^(p - 1) ≡ 1 (mod p)이며,
		A * A^(p - 2) ≡ B (mod p) 식과 동치이므로 바꿔줄 수있음.
		N * (N - 1) * ... * (N - K)는 팩토리얼로 구하고
		K!^(p - 2)는 분할 정복을 통해 구해줘야함
	*/
	A = 1;
	//A = N * (N - 1) * (N - 2) * ... * (N - K + 1);
	for (int i = N; i >= N - K + 1; i--)
		A = (A * i) % mod;
	
	B = 1;
	//B = K!
	for (int i = 1; i <= K; i++)
		B = (B * i) % mod;
	
	//B = (K!)^(p - 2)
	B = solve(mod - 2);

	printf("%lld\n", A * B % mod);
}