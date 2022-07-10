#include <iostream>
#include <vector>
#include <string>
#define INF 1e18
using namespace std;
typedef long long ll;

int tc;
int N;
ll num[9] = {0, 0, 1, 7, 4, 2, 0, 8, 10};//num[a] = b : a개 성냥개비로 만들 수 있는 수 b
ll dp[101] = {0, 0, 1, 7, 4, 2, 6, 8, 10,};

int main(void)
{
    for (int i = 9; i <= 100; i++)
    {
        dp[i] = INF;
        for (int j = 2; j <= 7; j++)
            dp[i] = min(dp[i - j] * 10 + num[j], dp[i]);//최솟값을 구하는 과정
    }

    cin >> tc;
    while (tc--)
    {
        cin >> N;

        cout << dp[N] << " ";//최솟값들을 저장해놨던 dp배열 출력

        if (N % 2 == 0)//짝수이면
        {
            int t = N / 2;//1을 만드는 데 2개 들어가므로
            while (t--)//t만큼 1출력
                cout << 1;
        }
        else//홀수이면
        {
            cout << 7;//7을 만드는데 3개 들어감
            int t = N / 2 - 1;//나머진 1을 출력
            while (t--)
                cout << 1;
        }
        cout << "\n";
    }
}