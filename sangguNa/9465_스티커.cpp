#include <iostream>
#include <algorithm>

using namespace std;

int sti[2][100001] = {0}; //스티커 비용
int dp[2][100001] = {0}; //dp[r][c] = a : r행 c열 까지의 스티커 비용 합

int main(void)
{
    int t;
    int n;

    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cin >> n;

        for (int j = 0; j < n; j++) //0행 값 채우기
            cin >> sti[0][j];

        for (int j = 0; j < n; j++) //1행 값 채우기
            cin >> sti[1][j];

        dp[0][0] = sti[0][0]; //초기값을 넣어줌
        dp[1][0] = sti[1][0];
        dp[0][1] = sti[0][1] + dp[1][0];
        dp[1][1] = sti[1][1] + dp[0][0];

        for (int j = 2; j < n; j++)
        {
            //문제에서 한 스티커를 선택하면 상,하,좌,우는 손상되어 사용할 수 없다했으므로 대각선을 고려해야함
            //한칸 뒤인 대각선과 두칸 뒤인 대각선 중 가장 큰 값을 dp에 더함
            dp[0][j] = sti[0][j] + max(dp[1][j - 1], dp[1][j - 2]);
            dp[1][j] = sti[1][j] + max(dp[0][j - 1], dp[0][j - 2]);
        }

        //두 행 중 가장 큰 값을 출력하고 i번째 케이스 종료
        cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;
    }
}