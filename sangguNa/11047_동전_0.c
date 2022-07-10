#include <stdio.h>

int N, K, count;
int A[10];

int main(void)
{
    scanf ("%d %d", &N, &K);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    
    int i = N - 1;//끝의 큰 동전부터 확인하기 위함
    count = 0;
    while (K > 0)
    {
        if (K < A[i])//목표값보다 동전 가치가 크면 뺄 수 없으므로 다음 동전으로 넘어감
            i--;
        else
        {
            K = K - A[i];//동전의 가치만큼 빼주고, 카운트 증가
            count++;
        }
    }

    printf("%d\n", count);
    return (0);
}