#include <iostream>

using namespace std;

int n; //계단 수
int stair[301]; //각 계단 당 점수
int dp[301]; //누적된 점수 저장

int main(void)
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> stair[i];

    //초기화 단계
    dp[0] = stair[0];
    dp[1] = max(stair[0], stair[0] + stair[1]);
    dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

    for (int i = 3; i < n; i++)
    {
        //'i번째 계단 이전(i - 1)을 안밟고 올라온 경우' vs '이전(i - 1)계단을 밟은 경우' 를 비교
        dp[i] = max(stair[i] + dp[i - 2], stair[i] + stair[i - 1] + dp[i - 3]);
    }

    cout << dp[n - 1] << endl;

    return (0);
}