#include <stdio.h>
#include <string.h>

int main(void)
{
    char S[20];
    int T, R;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d ", &R);
        scanf("%s", &S);

        for (int i = 0; i < strlen(S); i++)
        {
            for (int j = 0; j < R; j++)
            {
                printf("%c", S[i]);
            }
        }
        printf("\n");
    }
    return (0);
}