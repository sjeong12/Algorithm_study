#include <iostream>

using namespace std;

int n, s; //정수 갯수 n, 정수의 합(목표) s
int sub[20]; //수열 배열
int subresult = 0; //합이 s가 되는 부분수열의 갯수

void dfs(int idx, int sum) //부분수열 계산하는 함수(dfs 이용)
{
    sum = sum + sub[idx]; //일단 현재 인덱스를 더해줌

    if (idx >= n) //idx가 n범위를 넘어서면 종료
        return ;

    if (sum == s) //조건 충족하면 카운트 증가
        subresult++;

    dfs(idx + 1, sum - sub[idx]); //해당 숫자를 안 더했을 경우

    dfs(idx + 1, sum); //해당 숫자를 더했을 경우
}

int main(void)
{
    cin >> n >> s;

    for (int i = 0; i < n; i++)
        cin >> sub[i];
    
    dfs(0, 0);

    cout << subresult << endl;

    return (0);
}