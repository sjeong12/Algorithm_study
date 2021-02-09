#include <iostream>
#include <string>
#include <queue>

#define MAX 100
using namespace std;

int n, m, ans; //n은 열, m은 행, ans는 답
int map[MAX][MAX]; //입력을 받아 저장하는 배열
int dist[MAX][MAX]; //경로를 계산하는 배열, dist[a][b] = 1 이라는 값이 있다면, (a, b)에 오는데 1개의 문을 부셨음을 의미
bool visit[MAX][MAX]; //방문했는지 확인하는 배열

//하, 상, 우, 좌
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void BFS(int a, int b)
{
    queue<pair<int, int>> q; //큐 생성
    q.push(make_pair(a, b)); //초기 0, 0값을 넣어줌
    dist[a][b] = 0;

    while (q.empty() == 0)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue; //좌표가 음수거나, 벽 바깥으로 나갔다면 반복문 처음으로

            if (map[nx][ny] == 1) //찾아간 좌표가 벽(1)이라면
            {
                if (dist[nx][ny] > dist[x][y] + 1) //이동하려는 위치의 값 > 이전 위치에서의 값 + 1 이라면
                {
                    dist[nx][ny] = dist[x][y] + 1; //작은 값을 이동하려는 위치에 넣어주고 푸쉬
                    q.push(make_pair(nx, ny));
                }
            }
            else if (map[nx][ny] == 0) //찾아간 좌표가 벽이 아니라면(0)
            {
                if (dist[nx][ny] > dist[x][y]) //이동하려는 위치의 값 > 이전 위치에서의 값 이라면
                {
                    dist[nx][ny] = dist[x][y]; //작은 값을 이동하려는 위치에 넣어주고 푸쉬
                    q.push(make_pair(nx, ny)); 
                }
            }
        }
    }
    
}

int main(void)
{
    ans = 987654321; //최대값 배정
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        string inp;
        cin >> inp;
        for (int j = 0; j < inp.length(); j++)
        {
            map[i][j] = inp[j] - '0'; //입력받은 문자열을 하나씩 숫자로 바꿔 배열에 저장
            dist[i][j] = 987654321; //최대값 배정
        }
    }

    BFS(0, 0);

    cout << dist[m - 1][n - 1] << endl;
    
    return (0);
}