#include <stdio.h>

int N;
int r, g, b;
int dp[1000][3], arrR[1000], arrG[1000], arrB[1000];
//index 0은 빨강, 1은 초록, 2는 파랑
int Min(int a, int b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

int main(void)
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &r, &g, &b);
        arrR[i] = r;
        arrG[i] = g;
        arrB[i] = b;
    }

    dp[0][0] = arrR[0];
    dp[0][1] = arrG[0];
    dp[0][2] = arrB[0];

    for (int i = 1; i < N; i++)
    {
        //현재까지의 합을 구할 때 하나를 선택했다면 이전의 다른 두색의 최소를 구하고 더해줌
        dp[i][0] = arrR[i] + Min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = arrG[i] + Min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = arrB[i] + Min(dp[i - 1][0], dp[i - 1][1]);
    }

    printf("%d\n", Min(Min(dp[N -1][0], dp[N -1][1]), dp[N -1][2]));

    return (0);
}