#include <stdio.h>

int n; //수열의 크기
int a[1001] = {0, }; //입력받는 수열을 저장하는 배열
int dp[1001] = {0, }; //서로 비교해줄 배열
int max = 0; //최대값을 저장

int main(void)
{
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    
    for(int i = 1; i <= n; i++)
    {
        dp[i] = a[i]; //비교해줄 배열에도 값을 넣어줌
        for(int j = 1; j <= i; j++)
        {
            //증가하는 부분수열 이라면 && 현재 비교 값보다 (이전까지의 합 + 현재 값) 이 클 경우
            if(a[j] < a[i] && dp[i] < dp[j] + a[i])
            {
                dp[i] = dp[j] + a[i]; //(이전까지의 합 + 현재 값) 을 현재 비교값에 넣어준다
            }
        }
        if(max < dp[i]) //max 보다 현재 비교값이 더 크면 max에 넣어줌
            max = dp[i];
    }

    printf("%d\n", max);

    return (0);
}