#include <stdio.h>
#define MAX 101

int matrix[MAX][MAX] = {0};//인접행렬을 표현하기 위한 배열
int visited[MAX] = {0};
int virus_count = 0;

void DFS(int start, int n)
{
	int i;

	visited[start] = 1;
	virus_count++;

	for (int i = 1; i <= n; i++)
	{
		//start 에서 i로 갈 수 있고, 아직 방문하지 않은 곳이면 탐색
		if (matrix[start][i] && !visited[i])
			DFS(i, n);
	}
}

int main(void)
{
	int N, M;//컴퓨터 수, 연결되어있는 컴퓨터 쌍 수

	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int s = 0;
		int e = 0;
		scanf("%d %d", &s, &e);
		matrix[s][e] = 1;//인접 행렬에 대칭으로 입력
		matrix[e][s] = 1;
	}

	DFS(1, N);//1번 노드부터 탐색 시작

	printf("%d\n", virus_count - 1);

	return (0);
}