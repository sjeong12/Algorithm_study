#include <stdio.h>

int square[51][51];//배추밭
int visited[51][51];//방문여부
int m_x[4] = {-1, 0, 1, 0};
int m_y[4] = {0, -1, 0, 1};
int T, N, M, K;
int count_warm;//필요한 지렁이 갯수

void init(void)
{
    count_warm = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            square[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

void DFS(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int next_x = x + m_x[i];
        int next_y = y + m_y[i];
        
        if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
            continue; //범위 벗어나면 다음 좌표 탐색
        if (square[next_y][next_x] && !visited[next_y][next_x])
        {
            visited[next_y][next_x] = 1;
            DFS(next_y, next_x);
        }
    }
}

int main(void)
{
    int x, y;

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d %d", &N, &M, &K);
        
        init();//배열 및 변수 초기화
        for (int j = 0; j < K; j++)
        {
            scanf("%d %d", &x, &y);
            square[y][x] = 1;//배추 위치 기록
        }

        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (square[j][k] && !visited[j][k])
                {
                    visited[j][k] = 1;
                    DFS(j, k);//인접 배추 탐색
                    count_warm += 1;//지역 탐색을 다했으면 +1
                }
            }
        }

        printf("%d\n", count_warm);
    }
}