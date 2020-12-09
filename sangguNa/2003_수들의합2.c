#include <stdio.h>
//두 포인터 계열 문제
int main(void)
{
    int n; //수열의 길이
    int m; //목표 수의 합
    int arr[10000]; //수열을 저장하는 배열

    scanf("%d %d", &n, &m); //수열의 길이, 목표 수의 합을 입력받음

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]); //수열을 입력받음
    
    int count = 0; //목표 수의 합을 만족하는 경우의 수
    int sum = 0; //부분 수열의 합
    int start = 0; //오른쪽 포인터
    int end = 0; //왼쪽 포인터

    while (1)
    {
        if(sum >= m) //부분수열 합이 목표치보다 크면
            sum = sum - arr[start++]; //현재 왼쪽 포인터가 가리키는 값(start)을 sum에서 빼고 start를 오른쪽으로 한칸 이동
        else if(end == n) //오른쪽 포인터(end)가 끝까지 도착했으면
            break; //반복문을 끝냄
        else //부분수열 합이 목표치보다 작으면
            sum = sum + arr[end++]; //현재 오른쪽 포인터가 가리키는 값(end)을 sum에 더하고 end를 오른쪽으로 이동
        if(sum == m) //만약 부분수열 합이 목표 수열합이랑 같다면
            count++; //경우의 수 카운트 증가
    }

    printf("%d\n", count); //카운트 출력

    return(0);
}