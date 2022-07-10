#include <stdio.h>

int arr[10001] = {0, };

/*
    d(n)의 생성자가 있다 가정하고, 1부터 10000까지 반복문을 돌림
    숫자가 생성되면 해당 배열에 +1을 해서 기록
    만약 배열에 0이 기록된 숫자가 있다면, 그 수는 생성자가 없는 셀프넘버임
*/
void d(int n)
{
    int sum;

    sum = 0;
    sum += n;
    //10으로 나눠지는 숫자는 나머지가 0이므로 / 을 사용해서 보조해줌
    while (n % 10 || n / 10)
    {
        sum += n % 10;//각 자릿수를 더해줌
        n = n / 10;//자릿수를 줄임
    }
    arr[sum] += 1;
}

int main(void)
{
    for (int i = 1; i <= 10000; i++)
        d(i);
    
    for (int i = 1; i <= 10000; i++)
        if (arr[i] == 0)
            printf("%d\n", i);
    
    return (0);
}