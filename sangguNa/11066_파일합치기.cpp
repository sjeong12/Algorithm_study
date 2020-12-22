#include <stdio.h>
#include <algorithm>
#define INF 1000000007
using namespace std;

int t; //테스트 데이터 갯수
int k; //소설 장의 수
int dp[501][501]; //dp[a][b]의 의미는 a부터 b까지 각 장을 합친 최솟값(a < b), 만약 dp[a][a] = cost[a]이고, 구간비용은 0
int cost[501]; //입력된 장의 비용(크기)
int sum[501]; //sum[a]의 의미는 0부터 a까지의 장을 더한 값
//입력값이 40,30,30,50 이라면 sum[] = {0, 40, 70, 100, 150}
//sum 배열이 필요한 이유 : 
//ex) 3 1 2 -> dp[1][1] + dp[2][3] + sum[3] = 0 + 3 + 6 = 9
//여기서 sum[3] = cost[1] + dp[2][3] = 6과 같다

int main(void)
{
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &k);

        for(int i = 1; i <= k; i++)
        {
            scanf("%d", &cost[i]);
            sum[i] = sum[i - 1] + cost[i]; //이전 sum에다가 입력받은 장을 더해줌
        }

        for(int d = 1; d < k; d++) //d는 경계선(끊어주는 부분)
        {
            for(int tx = 1; tx + d <= k; tx++) //tx는 구간 시작점, ty는 구간 끝점, mid는 경계선
            {
                int ty = tx + d; //끝점 지정
                dp[tx][ty] = INF; //최대값으로 지정

                for(int mid = tx; mid < ty; mid++)
                {   
                    //printf("before trans : ");
                    //printf("%d %d %d %d %d %d %d %d\n", tx, mid, ty, dp[tx][ty], dp[tx][mid], dp[mid+1][ty], sum[ty], sum[tx-1]);

                    dp[tx][ty] = 
                    min(dp[tx][ty], dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1]);
                    //점화식 : (tx ~ mid까지의 합) + (mid+1 ~ ty까지의 합) + sum[]에서 tx ~ ty 구간의 합

                    //printf("after trans : ");
                    //printf("%d %d %d %d %d %d %d %d\n", tx, mid, ty, dp[tx][ty], dp[tx][mid], dp[mid+1][ty], sum[ty], sum[tx-1]);
                    //각각의 구간 비용을 구해서 최소비용을 dp[tx][ty]에 넣어줌
                }
            }
        }
        printf("%d\n", dp[1][k]); //1부터 k까지 최소 비용합 출력
    }
    
    return(0);
}