#include <iostream>
using namespace std;

int arr[501][501] = {};
int dp[501][501] = {};//방문한 곳의 경우의 수 저장
bool visited[501][501] = {0};//방문여부
int M, N;
int y_arr[4] = {1, 0, -1, 0};
int x_arr[4] = {0, 1, 0, -1};

int dfs(int cy, int cx)
{
    if (cy == M && cx == N)
        return (1);//종점에 도착하면 1 반환
    if (visited[cy][cx])
        return (dp[cy][cx]);//이미 방문한 곳이면 해당 dp값 반환
    visited[cy][cx] = 1;
    for (int i = 0; i < 4; i++)
    {
        int next_y = cy + y_arr[i];//4방향 탐색을 for문으로 돌림
        int next_x = cx + x_arr[i];

        if (next_y > 0 && next_y <= M && next_x > 0 && next_x <= N)
            if (arr[cy][cx] > arr[next_y][next_x])//내리막길을 발견했으면
                dp[cy][cx] += dfs(next_y, next_x);//계산하고 dp배열에 값을 저장
    }
    return (dp[cy][cx]);
}

int main(void)
{
    cin >> M >> N;
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            cin >> arr[i][j];
    
    cout << dfs(1, 1) << "\n";
    return (0);
}