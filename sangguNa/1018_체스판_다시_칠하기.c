#include <stdio.h>
#define MINF(a, b) a < b ? a : b

int main(void)
{
    int N, M;
    char arr[50][50];
    int cntW = 0, cntB = 0;
    int min = 80;

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%s", &arr[i]);

    for (int i = 0; i < N - 7; i++) //8, 8일 경우, 체크해야할 판을 옮길 수 없으므로 1번만 시행
    {
        for (int j = 0; j < M - 7; j++)
        {
            cntW = 0;
            cntB = 0;
            for (int a = i; a < i + 8; a++)
            {
                for (int b = j; b < j + 8; b++)
                {
                    if ((a + b) % 2 == 0)//a+b의 합이 짝수인 칸
                    {
                        if (arr[a][b] == 'B')
                            cntW++;
                        else
                            cntB++;
                    }
                    else//반대로 홀수인 칸
                    {
                        if (arr[a][b] == 'B')
                            cntB++;
                        else
                            cntW++;
                    }
                }
            }
            min = MINF(min, cntB);
            min = MINF(min, cntW);
        }
    }
    printf("%d\n", min);
    return (0);
}