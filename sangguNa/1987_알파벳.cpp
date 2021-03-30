#include <iostream>

#define MAX 20
using namespace std;

int r, c, answer = 0; //r : 행, c : 열, 답
char map[MAX][MAX];
bool visit[26];

int dx[] = {0, 0, 1, -1}; //가로이동(오른쪽, 왼쪽)
int dy[] = {1, -1, 0, 0}; //세로이동(아래, 위)

void DFS(int x, int y, int cnt) //백트래킹을 위한 함수
{
    answer = max(answer, cnt); //둘 중 큰 것을 answer 변수에 넣어줌
    
    for (int i = 0; i < 4; i++) //상하좌우를 방문해서, 중복된 알파벳을 만나지 않는 경우를 증가시킴
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < r && ny < c) //맵 바깥으로 넘어가지 않았다면
        {
            if (visit[map[nx][ny] - 'A'] == false) //만약 방문하지 않았다면
            {
                visit[map[nx][ny] - 'A'] = true; //방문했다고 바꾸기
                DFS(nx, ny, cnt + 1); //다음 블록에서 같은 방법을 진행
                visit[map[nx][ny] - 'A'] = false; //DFS가 끝났다면 다른 경우도 살펴봐야 하므로 false로 바꾸기
            }
        }
    }
}

int main(void)
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
        }
    }

    visit[map[0][0] - 'A'] = true; //처음 지역(0, 0)에서 무조건 시작하므로 방문했다고 표시
    DFS(0, 0, 1);

    cout << answer << endl;
}