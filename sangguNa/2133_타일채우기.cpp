#include <iostream>
using namespace std;
/*
    2133_타일채우기
    일단 가로 길이가 홀수일 때는 타일을 만들 수 없으므로 홀수일 때 갯수는 0
    가로길이 N = 2 일때 만들수 있는 가짓수는 3가지
    N = 4일때 N = 2 일때 타일을 서로 붙인 경우의 수(3 * 3) + 새로 만들어지는 타일 2가지 = 11가지
    이런 조합으로 계속 구하면 다음과 같이 짤 수 있음
*/
int main()
{
    int N;
    int dp[31] = {1, 0, 3};
    cin >> N;
    
    if (N % 2 == 0)
        for (int i = 4; i <= N; i += 2){
            dp[i] = dp[i - 2] * 3;
            
            for(int j = 4; i - j >= 0; j += 2)
                dp[i] += dp[i - j] * 2;
        }
    
    cout << dp[N] << endl;
    
    return 0;
}