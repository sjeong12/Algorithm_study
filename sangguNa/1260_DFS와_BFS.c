#include <stdio.h>
#define MAX 1001

int matrix[MAX][MAX];//인접행렬을 표현하기 위한 배열
int visited[MAX * MAX];

void DFS(int v, int n)
{
    printf("%d ", v);//정점 출력
    
    visited[v] = 1;//왔던 곳이라고 기억

    for (int i = 1; i <= n; i++)//인접 정점 체크
    {
        if (!visited[i] && matrix[v][i])//아직 왔던 곳이 아니고 이동이 가능하면
            DFS(i, n);//다음 정점 탐색
    }
}

void BFS(int v, int n)
{
    int front = -1, rear = -1;//큐를 사용하기위한 변수 선언
    int queue[MAX * MAX] = {0};
    
    rear++;//큐에 첫번째 값 입력
    queue[rear] = v;

    visited[v] = 1;

    printf("%d ", v);
    
    while (front < rear)//BFS
    {
        front++;//큐에서 꺼냄
        int next_v = queue[front];

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && matrix[next_v][i])//아직 왔던 곳이 아니고 이동 가능하면
            {
                rear++;//다음 정점 입력 및 출력
                visited[i] = 1;
                queue[rear] = i;
                printf("%d ", i);
            }
        }
    }
}

void init(int N)
{
    printf("\n");
    for (int i = 1; i <= N; i++)
        visited[i] = 0;
}

int main(void)
{
    int N, M, V;

    scanf("%d %d %d", &N, &M, &V);
    for (int i = 0; i < M; i++)
    {
        int s = 0;
        int e = 0;
        scanf("%d %d", &s, &e);
        matrix[s][e] = 1;//인접 행렬에 대칭으로 입력
        matrix[e][s] = 1;
    }

    DFS(V, N);
    init(N);
    BFS(V, N);

    return (0);
}