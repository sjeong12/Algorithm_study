#include <stdio.h>

int n; //구매하려는 카드의 갯수
int pay[1001]; //카드 n개가 들어있을때 지불해야하는 가격
int max_pay[1001]; //카드 n개를 구매할때 들어가는 비용의 최대값

/* 예
    pay[1] = 5 : 카드 1장이 들어가있는 팩의 비용 : 5
    pay[2] = 2 : 카드 3장이 들어가있는 팩의 비용 : 2
    max_pay[2] = 10 : 카드 2장을 구매할때 들어가는 최대 비용, 여기선 1장 팩 + 1장 팩 = 10원 
*/

//둘 중 가장 큰 값을 리턴하는 함수
int compare_pay(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

//카드팩 비용 최댓값을 구하는 함수
void solve_pay(int n)
{
    pay[0] = max_pay[0] = 0; //0번째는 0으로 초기화
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            max_pay[i] = compare_pay(max_pay[i], max_pay[i - j] + pay[j]);
        }
    }
}

int main(void)
{
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &pay[i]);
    }

    solve_pay(n);

    printf("%d\n", max_pay[n]); //비용 최댓값 출력
    return(0);
}

/*
    이 문제는 카드 N개를 구매할 때의 최대비용을 구해야 하므로, 마지막에 1개짜리 카드팩을 구매하는 경우를 생각해보자.
   마지막에 1개짜리 카드팩을 구매한다고 가정하면, 그 전에서 N-1개의 카드를 구매해야 하고, 이를 식으로 나타내면
   DP[N-1] + Arr[1] 이 된다. N-1개를 구매했을 때의 최대비용과 1개를 구매했을 때의 가격, 즉 총 N개를 구매한 가격이
   나오게 된다.
   마지막에 2장짜리 카드팩을 사는 것을 고려해보면, DP[N-2] + Arr[2]가 된다.
   마지막에 N장짜리 카드팩을 사는 것을 고려해보면, DP[N-N] + Arr[N]이 되게 된다.
   이 문제는, 최대비용을 구해야 하므로, 마지막에 카드를 1장 사는 것 부터 최대 N장 사는 것 까지 모두 다 고려해서
   비교해 주어야 한다.
   따라서, 위의 말을 토대로 점화식을 도출해본다면 DP[N] = DP[N] vs (DP[N-a] + Arr[a]) 가 된다.
   출처: https://yabmoons.tistory.com/23 [얍문's Coding World..]
*/