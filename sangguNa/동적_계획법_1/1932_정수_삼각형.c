#include <stdio.h>
#include <string.h>

int tri[501][501];
int dp[501][501];
int N;

int Max(int a, int b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

int solve(int y, int x)
{
    int result;

    if (y > N || x > N)
        return (-1);
    if (y == N)//맨 밑에 도달했으면 그 수를 그냥 반환
        return (tri[y][x]);
    if (dp[y][x] != -1)//이미 계산된 수면 그 수를 반환
        return (dp[y][x]);
    result = 0;
    //두 경우 중 큰 수를 result에 저장
    result = Max(tri[y][x] + solve(y + 1, x), tri[y][x] + solve(y + 1, x + 1));
    return (dp[y][x] = result);
}

int main(void)
{
    int result;

    result = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= i; j++)
            scanf("%d", &tri[i][j]);//삼각형 채우기
    memset(dp, -1, sizeof(dp));//dp 배열을 -1로 초기화
    result = solve(1, 1);
    printf("%d\n", result);
}