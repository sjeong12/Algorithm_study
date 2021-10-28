#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 101

using namespace std;

int N, M, K;
int cnt = 0;
int arr[MAX][MAX];
bool visit[MAX][MAX];

int dx[4] = {0, 0, 1, -1};//아래, 위, 왼쪽, 오른쪽 이동
int dy[4] = {1, -1, 0, 0};

void DFS(int x, int y)
{
    visit[x][y] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M)
            continue;
        if (arr[nx][ny] == 0 && !visit[nx][ny])
            DFS(nx, ny);
    }
}

int main(void)
{
    vector<int> vec;
    
    cin >> N >> M >> K;

    //x, y좌표를 입력받고, 그 구간을 1 및 방문했다고 표시
    while (K--)
    {
        int x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        for (int i = x1; i < x2; i++)
        {
            for (int j = y1; j < y2; j++)
            {
                arr[i][j] = 1;
                visit[i][j] = true;
            }
        }
    }
    
    //영역 외의 곳을 DFS를 이용하여 탐색
    //빈 영역 갯수를 cnt에 저장하여 vec에 push_back
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 0 && !visit[i][j])
            {
                cnt = 0;
                DFS(i, j);
                vec.push_back(cnt);
            }
        }
    }

    sort(vec.begin(), vec.end());//정렬
    cout << vec.size() << endl;//벡터 출력
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    return (0);
}