#include <iostream>
using namespace std;

int N, ans = 987654321;
int map[11][11]; //각 도시의 비용을 저장하기 위한 배열, map[a][b] = c : a에서 b가는데 들어가는 비용은 c다
bool visit[11]; //방문했는지 확인하기 위한 배열
int start_idx; //시작 지점

void dfs(int idx, int cost, int cnt) //현재(또는 출발)도시, 비용, 카운트(깊이) -> 도시비용을 dfs를 이용해서 계산
{
    if (cnt == N - 1)
    {
        if (map[idx][start_idx])
        {
            ans = min(ans, cost + map[idx][start_idx]); //이전 ans와 비교해 최소비용을 ans에 넣어줌
            return ;
        }
    }

    for (int i = 1; i <= N; i++) 
    {
        if (map[idx][i] && visit[i] == false) //idx -> i로 가는 비용이 존재하고 && 방문한 적이 없다면
        {
            visit[i] = true; //방문했다고 저장
            dfs(i, cost + map[idx][i], cnt + 1); //다음 도시로 이동
            visit[i] = false; //초기화
        }
    }
}

int main(void)
{
    cin >> N;

    for (int i = 1; i <= N; i++) //비용 입력
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        start_idx = i; //시작 도시 위치를 start_idx에 저장
        visit[i] = true; //시작도시를 방문했다고 체크
        dfs(i, 0, 0); //탐색 시작
        visit[i] = false; //초기화
    }

    cout << ans << endl;
    
    return (0);
}