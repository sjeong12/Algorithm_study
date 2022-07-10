#include <stdio.h>

int N;
int arr[1000001];

int main(void)
{
    scanf("%d", &N);

    arr[0] = 0;
    arr[1] = 1;//1
    arr[2] = 2;//00, 11
    /*
        n = 3 : 100, 001, 111
        n = 4 : 0000, 1100, 1001, 0011, 1111
        ...
        N - 2의 수에선 맨뒤 또는 앞에 00을 붙이고,
        N - 1의 수에서 맨 앞에 1을 붙이는 규칙을 이용하면
        중복없이 수을 만들 수있다함
    */

    for (int i = 3; i <= N; i++)//피보나치 수열의 갯수를 따름.신기함
        arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
    
    printf("%d\n", arr[N]);

    return (0);
}