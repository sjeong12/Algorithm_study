#include <stdio.h>

int main(void)
{
    int T;
    int H, W, N;

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d %d", &H, &W, &N);
        if ((N % H) == 0)
            printf("%d\n", H * 100 + N / H);//N % H == 0 인 경우, 층은 H, 호수는 N / H 로 계산
        else
            printf("%d\n", (N % H) * 100 + (N / H) + 1);//그 외는 층은 N % H, 호수는 N / H + 1로 계산
    }
    return (0);
}