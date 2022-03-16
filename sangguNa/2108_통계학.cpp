#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}

int main(void)
{
	int N;
	int arr[500000] = {0, };
	int cnt[8001] = {0};
	int median, most, range;
	int sum = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	qsort(arr, N, sizeof(int), compare);

	//산술 평균
	for (int i = 0; i < N; i++)
		sum += arr[i];

	//중앙값
	if (N == 1)
		median = arr[0];
	else
		median = arr[(N + 1) / 2 - 1];

	//최빈값
	int max = 0, count = 0;
	int i, idx;
	for (i = 0; i < N; i++)
	{
		idx = arr[i] + 4000;
		cnt[idx] += 1;
		
		if (cnt[idx] > max)
			max = cnt[idx];
	}
	for (i = 0, idx = 0; i < 8001; i++)
	{
		if (cnt[i] == 0)
			continue;
		if (cnt[i] == max)
		{
			if (count == 0)
			{
				idx = i;
				count += 1;
			}
			else if (count == 1)
			{
				idx = i;
				break;
			}
		}
	}
	most = idx - 4000;

	//범위
	range = arr[N - 1] - arr[0];

	int mean = round(double(sum) / N);
	std::cout << mean << "\n";
	std::cout << median << "\n";
	std::cout << most << "\n";
	std::cout << range << "\n";
	return (0);
}