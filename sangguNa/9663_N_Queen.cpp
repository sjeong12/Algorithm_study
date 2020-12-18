#include <stdio.h>
#include <math.h>
#define MAX 15
//백트래킹, 브루트포스 문제
int col[MAX]; //최대 열 갯수
int n = 0; //입력받는 열 갯수
int count = 0; //n-queen 답 갯수

bool check(int depth) //같은행, 대각선에 퀸이 있는지 검사하는 함수
{
    for(int i = 0; i < depth; i++) //인자로 들어온 수를 기준으로 확인
    {
        //같은 행에 존재하거나 || 대각선에 위치하면
        if(col[i] == col[depth] || abs(col[depth] - col[i]) == depth - i)
            return false; //false 반환
    }
    return true; //존재하지 않으면 true 반환, 다음 열로 넘어가게됨
}

void nqueen(int a) //퀸을 배치하는 함수
{
    if(a == n) //여기까지 왔다는건 서로 공격하지 않는 배치가 완성됐다는 뜻이므로 count 증가
        count++;
    else
    {
        for(int i = 0; i < n; i++) //입력받은 n만큼 퀸을 배치하면서 확인
        {
            col[a] = i;
            if(check(a)) //주위에 공격가능한 퀸이 없으면
                nqueen(a + 1); //다음 열로 넘어감
        }
    }
}

int main(void)
{
    scanf("%d", &n);

    nqueen(0); //풀이 시작

    printf("%d\n", count);
}
