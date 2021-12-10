#include <stdio.h>

int T, k, n;
int floor[15][15] = {0, };

int main(void)
{
    scanf("%d", &T);

    //토대가 되는 0층부터 하나씩 채워줌
    for(int i = 0; i <= 14; i++)
        floor[0][i] = i;

    /*
        예를 들어, 2층 3호의 인원은 1층 1~3호의 인원수의 합이라 할 때
        f[2][3] = f[1][3] + f[1][2] + f[1][1] 을 세울 수 있다.
        그리고 이전 f[2][2] = f[1][2] + f[1][1] 을 세울 수 있다.
        즉, 구하고자 하는 층의 인원수는
            아래층의 같은 호수[n - 1][k] 와 현재층 이전 호수[n][k - 1]의 합이다
        따라서 f[2][3] = f[1][3] + f[2][2]
         -> f[n][k] = f[n - 1][k] + f[n][k - 1]을 세울 수 있다. 
    */
    for (int i = 1; i <= 14; i++)
        for (int j = 1; j <= 14; j++)
            floor[i][j] = floor[i - 1][j] + floor[i][j - 1];

    while (--T >= 0)
    {
        scanf("%d", &k);
        scanf("%d", &n);

        printf("%d\n", floor[k][n]);
    }
}