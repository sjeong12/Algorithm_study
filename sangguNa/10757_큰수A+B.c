#include <stdio.h>
#include <string.h>

void reverse(char *arr)
{
	int temp;
	int len = strlen(arr);
	for (int i = 0; i < len / 2; i++)//i번째와 len-i-1 번째 자리의 단어를 서로 바꿈
	{
		temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;
	}
}

int main(void)
{
	char A[10002] = {0, };
	char B[10002] = {0, };
	char res[10003] = {0, };
	int carry = 0;
	int len = 0;

	scanf("%s %s", &A, &B);
	reverse(A);
	reverse(B);
	if (strlen(A) > strlen(B))//큰 수 기준으로 길이 저장
		len = strlen(A);
	else
		len = strlen(B);
	
	for (int i = 0; i < len; i++)
	{
		int sum = A[i] - '0' + B[i] - '0' + carry;
		if (sum < 0)//자릿수가 다른 경우, 둘 중 하나가 null이기 때문에 sum에서 -'0' 이 한번 더 계산됨
			sum += '0';// 그러므로 +'0' 을 해서 맞춰줌
		if (sum > 9)
			carry = 1;
		else
			carry = 0;
		res[i] = sum % 10 + '0';//다시 문자로 전환
	}
	if (carry == 1)
		res[len] = '1';
	reverse(res);//뒤집어놓은 상태로 계산했으므로 다시 뒤집어서 원상복구
	printf("%s\n", res);
	return (0);
}