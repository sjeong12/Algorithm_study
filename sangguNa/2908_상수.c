#include <stdio.h>

int main(void)
{
	int A, B;
	int temp, answer;
	
	scanf("%d %d", &A, &B);
	temp = 0;
	while (A > 0)
	{
		temp = temp * 10 + (A % 10);
		A /= 10;
	}
	A = temp;

	temp = 0;
	while (B > 0)
	{
		temp = temp * 10 + (B % 10);
		B /= 10;
	}
	B = temp;

	if (A > B)
		answer = A;
	else
		answer = B;
	printf("%d\n", answer);
}