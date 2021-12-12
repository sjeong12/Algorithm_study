#include <stdio.h>

int N, M;
int card[100] = {0, };
int min = 0, sum;

int main(void)
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
        scanf("%d", &card[i]);
    
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            for (int k = j + 1; k < N; k++)
            {
                sum = card[i] + card[j] + card[k];
                if (sum > min && sum <= M)
                    min = sum;
            }

    printf("%d\n", min);
    return (0);
}