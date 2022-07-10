#include <stdio.h>
#include <stdlib.h>

int Max(int a, int b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

int main(void)
{
    int N, S;
    int max = 0, result = 0;
    int arr[501] = {0, };
    int dp[501] = {0, };

    scanf("%d", &N);

    //왼쪽 전봇대 S 번째는 오른쪽 전봇대 arr[S] = ? 에 연결되있다
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &S);
        scanf("%d", &arr[S]);
    }

    //전깃줄의 최소 갯수를 구하는 방법은
    //'전체 전깃줄 수 - 최대한 남은 전깃줄 수' 라고 함
    //즉, '전깃줄 수 N - 오른쪽 전봇대의 전깃줄 arr[N]에서 가장 긴 증가하는 부분수열'
    //이라고 하는데, 잘 이해못하겠음
    //아래 코드는 가장 긴 증가하는 부분수열을 구하는 코드
    for (int i = 1; i <= 500; i++)
    {
        if (arr[i] != 0)
        {
            max = 0;
            for (int j = 0; j < i; j++)
            {
                if (arr[i] > arr[j])
                    if (dp[j] > max)
                        max = dp[j];
            }
            dp[i] = max + 1;
            result = Max(result, dp[i]);
        }
    }
    
    printf("%d\n", N - result);

    return (0);
}