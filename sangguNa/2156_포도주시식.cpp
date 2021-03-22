#include <iostream>
using namespace std;

int n;
int arr[10001]; //각각의 포도주 양을 담는 배열
int dp[10001]; //dp[n] : n번째 잔을 마셨을 때 까지의 포도주 양


int main(void)
{
    int i;

    cin >> n;
    for (i = 1; i <= n; i++)//각 잔의 포도주 양 입력 받음
        cin >> arr[i];
    
    dp[1] = arr[1];//첫 잔 마셨음
    dp[2] = arr[1] + arr[2];//첫 번째 + 두번째 잔 마심

    //각각의 경우를 비교해서 가장 많은 양을 저장함
    //(i - 2)번째 양의 합 + i번째 잔의 양 또는 (i - 3)번째 양의 합 + (i - 1)번째 잔의 양 + i번째 잔의 양
    //또는 아예 안마시기(dp[i - 1], 즉 이전 양의 합 그대로)
    for (i = 3; i <= n; i++)
        dp[i] = max(dp[i - 2] + arr[i], max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 1]));
    
    cout << dp[n] << endl;
}