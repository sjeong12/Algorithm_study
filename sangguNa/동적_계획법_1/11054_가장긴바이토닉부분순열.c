#include <stdio.h>

int plus_dp[1001]; //전역변수로 설정, 인덱스 1부터 값을 저장할꺼라 크기를 1001로 설정
int minus_dp[1001];

int main(void)
{
    int n; //수열의 크기를 입력받는 변수
    int i, j; //반복자
    int arr[1001]; //수열을 입력받는 배열, 인덱스 1부터 값을 저장할꺼라 크기를 1001로 설정

    scanf("%d", &n); // 수열의 크기를 입력받음

    for(i = 1; i <= n; i++)
        scanf("%d", &arr[i]); //수열의 크기만큼 수를 입력받음

    arr[0] = arr[1]; //인덱스 0번째의 자리가 비므로 1번째의 값을 넣어둠

    for(i = 1; i <= n; i++) //앞에서부터 탐색
    {
        int max = 0; //증가하는 부분 수열의 길이, 0으로 초기화
        for(j = 0; j < i; j++)
        {
            if(arr[i] > arr[j]) //만약 뒤(i)의 인덱스보다 앞(i보다 작은)의 인덱스의 크기가 크면
            {
                if(plus_dp[j] > max) //그리고 dp[j]의 값이 max보다 크면
                    max = plus_dp[j]; //max가 저장되어있는 dp[j]의 값을 max에 저장
            }
        }
        plus_dp[i] = max + 1; //해당 i 단계에 max + 1값을 저장(0번째라도 길이 1부터 시작하게됨)
    }

    for(i = n; i >= 1; i--) //뒤에서부터 탐색
    {
        int max = 0; //감소하는 부분 수열의 길이, 0으로 초기화
        for(j = n; j >= i; j--)
        {
            if(arr[i] > arr[j]) //만약 앞(i)의 인덱스보다 뒤(i보다 큰)의 인덱스의 크기가 크면
            {
                if(minus_dp[j] > max) //그리고 dp[j]의 값이 max보다 크면
                    max = minus_dp[j]; //max가 저장되어있는 dp[j]의 값을 max에 저장
            }
        }
        minus_dp[i] = max + 1; //해당 i 단계에 max + 1값을 저장(0번째라도 길이 1부터 시작하게됨)
    }

    int max = 0;
    for(i = 1; i <= n; i++)
    {
        //-1을 해주는 이유는 1,2,3,2,1 을 예시로 들면 증가할때, 감소할때
        //3이라는 원소가 중복되기 때문
        if(max < plus_dp[i] + minus_dp[i] - 1)
            max = plus_dp[i] + minus_dp[i] - 1;
    }

    printf("%d\n", max);

    return (0);
}