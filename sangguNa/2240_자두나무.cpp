#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T, W; //T : 시간, W : 최대 이동 횟수
int jadu[1001];
int dp[3][1001][31]; //dp[a][b][c]-> a:자두나무 번호 / b:초(시간) / c:이동 횟수

int jadu_count(int tree, int sec, int move)
{
    if (sec == T)
        return 0;
    
    int &result = dp[tree][sec][move]; //dp배열을 result란 참조자(별명)에 넣어줌

    if (result != -1)
        return result;

    if (jadu[sec] == tree) //현재있는 나무에서 자두가 떨어진다면
    {
        if (move < W) //아직 움직일 수 있다면
        {
            //max(움직이지 않은 경우 획득 / 움직인 경우 획득하지 못함)
            return result = max(1 + jadu_count(tree, sec + 1, move), jadu_count(3 - tree, sec + 1, move + 1));
        }
        else
            return result = 1 + jadu_count(tree, sec + 1, move); //움직일 수 없는 경우 그자리에서 획득
    }
    else //반대쪽 나무에서 자두가 떨어진다면
    {
        if (move < W)
        {
            //max(움직이지 않은 경우 획득하지 못함 / 움직인 경우 획득함)
            return result = max(jadu_count(tree, sec + 1, move), 1 + jadu_count(3 - tree, sec + 1, move + 1));
        }
        else
            return result = jadu_count(tree, sec + 1, move); //움직일 수 없기 때문에 반대쪽 나무 자두룰 획득 못함
    }
}

int main(void)
{
    cin >> T >> W;

    for (int i = 0; i < T; i++)
        cin >> jadu[i];

    memset(dp, -1, sizeof(dp)); //일단 -1로 초기화

    cout << jadu_count(1, 0, 0) << endl;

    return (0);
}