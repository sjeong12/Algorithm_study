#include <stdio.h>

int arr[21][21][21];//3차원 배열로 될까 해서 했는데 됨
int a, b, c;
int answer;

int solve(int a, int b, int c)//문제의 조건대로 만든 함수
{
    if (a <= 0 || b <= 0 || c <= 0)
        return (1);
    if (a > 20 || b > 20 || c > 20)
        return solve(20, 20, 20);
    if (arr[a][b][c])//이미 존재하는 배열이면 또 계산할 필요없이 바로 반환
        return (arr[a][b][c]);
    if (a < b && b < c)
    {
        arr[a][b][c] = solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c);
        return (arr[a][b][c]);
    }
    arr[a][b][c] = solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);
    return (arr[a][b][c]);
}

int main(void)
{
    while (true)
    {
        scanf("%d %d %d", &a, &b, &c);

        if (a == -1 && b == -1 && c == -1)
            break ;
        
        answer = solve(a, b, c);

        printf("w(%d, %d, %d) = %d\n", a, b, c, answer);
    }
}