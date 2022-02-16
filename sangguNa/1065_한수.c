#include <stdio.h>

int main(void)
{
	int input;
	int count;
	int arr[3];
	int temp = 0;

	scanf("%d", &input);
	for (int i = 1; i <= input; i++)//1부터 input 까지의 한수 갯수 구하기
	{
		if (i < 100)//1, 2자리 수는 한수나 다름없음. 99까진 한수이므로 99개
			count = i;
		else if (i == 1000)//1000은 한수가 아니고, 1000 이하까지만 계산하므로break;
			break;
		else if (i >= 100)
		{
			int k = 0;
			temp = i;
			while (temp > 0)//각 자릿수를 배열에 저장
			{
				arr[k] = temp % 10;
				temp /= 10;
				k++;
			}
			if (arr[0] - arr[1] == arr[1] - arr[2])//각 자리의 차이가 동일하면 한수
				count++;
		}
	}
	printf("%d\n", count);
}