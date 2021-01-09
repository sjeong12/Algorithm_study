#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//파일 합치기 문제와 유사함
int row[501], col[501]; //행, 열
int dp[501][501]; //dp[i][j]의 의미는 구간[i, j]에서의 최소 행렬 곱셈 횟수
//즉, dp[i][j] = k가 i부터 j까지 이동할 때 (dp[i][k] + dp[k + 1][j] + row[i] * col[k] * col[j])의 최솟값이라 나타낼 수 있음
//ex) 입력값이 5*3, 3*2라 할때 dp[0][0] = 0, dp[0][1] = 5*3*2 = 30임

int main(void)
{
    int n; //행렬의 개수
    int r; //행의 크기
    int c; //열의 크기

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> r >> c; //입력받은 행, 열 크기를 배열에 저장
        row[i] = r;
        col[i] = c;
    }
    for (int len = 1; len < n; len++) //len은 볼 행렬의 갯수
    {
        for (int i = 0; i < n; i++) //i는 시작 행렬의 인덱스
        {
            int j = i + len; //j는 끝행렬?
            if (j >= n)
                break;
            int result = 2147483647;
            for (int k = i; k < j; k++) //k는 곱셈 분기의 인덱스
            {
                result = min(result, dp[i][k] + dp[k + 1][j] + row[i] * col[k] * col[j]); //최소 행렬 곱셈 횟수를 result에 저장
            }
            dp[i][j] = result; //i부터 j까지 구간에서 최소 횟수를 dp[i][j]에 저장
        }
    }
    cout << dp[0][n - 1] << "\n"; //0부터 n까지 구간에서 최소 횟수 출력

    return (0);
}