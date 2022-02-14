#include <stdio.h>

long long sum(int *a, int n)
{
    long long ans;

    ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[i];
    return (ans);
}

int main(void)
{
    int a[3000000];
    int n;
    long long result = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    result = sum(a, n);

    printf("%d\n", result);
}