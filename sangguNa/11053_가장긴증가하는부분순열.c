#include <stdio.h>

int dp[1001]; //전역변수로 설정, 인덱스 1부터 값을 저장할꺼라 크기를 1001로 설정
int main(void)
{
    int n; //수열의 크기를 입력받는 변수
    int i, j; //반복자
    int arr[1001]; //수열을 입력받는 배열, 인덱스 1부터 값을 저장할꺼라 크기를 1001로 설정

    scanf("%d", &n); // 수열의 크기를 입력받음

    for(i = 1; i <= n; i++)
        scanf("%d", &arr[i]); //수열의 크기만큼 수를 입력받음

    arr[0] = arr[1]; //인덱스 0번째의 자리가 비므로 1번째의 값을 넣어둠

    for(i = 1; i <= n; i++)
    {
        int max = 0; //감소하는 부분 수열의 길이, 0으로 초기화
        for(j = 0; j < i; j++)
        {
            if(arr[i] > arr[j]) //만약 뒤(i)의 인덱스보다 앞(i보다 작은)의 인덱스의 크기가 작으면
            {
                if(dp[j] > max) //그리고 dp[j]의 값이 max보다 크면
                    max = dp[j]; //max가 저장되어있는 dp[j]의 값을 max에 저장
            }
        }
        dp[i] = max + 1; //해당 i 단계에 max + 1값을 저장(0번째라도 길이 1부터 시작하게됨)
    }

    int max = 0; //0으로 초기화
    for(i = 1; i <= n; i++)
    {
        if(max < dp[i]) //max값이 dp[i]보다 작으면
            max = dp[i]; //max에 dp[i]값을 넣음
    }
    printf("%d\n", max); //수열 길이 값 출력

    return (0);
}