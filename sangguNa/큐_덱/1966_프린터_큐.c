#include <stdio.h>

int cnt, N, M;
int arr[100] = {0, };
int ans, front, max;

int main(void)
{
    scanf("%d", &cnt);

    for (int i = 0; i < cnt; i++)
    {
        scanf("%d %d", &N, &M);
        ans = 1;
        front = 0;
        max = 0;
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[j]);
        
        while (1)
        {
            for (int k = 0; k < N; k++)
            {
                if (arr[k] > max)//가장 높은 중요도 크기를 max에 저장
                    max = arr[k];
            }

            while (arr[front] != max)//원형 큐 사용, arr 값이 max가 아니라면 계속 탐색
                front = (front + 1) % N;
            
            if (front == M)
                break ;
            arr[front] = 0;//출력한 것은 가장 낮은 중요도로 바꿔줌
            front = (front + 1) % N;
            max = 0;
            ans++;
        }
        printf("%d\n", ans);
    }
    return (0);
}