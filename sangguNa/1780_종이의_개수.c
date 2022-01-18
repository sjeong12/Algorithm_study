#include <stdio.h>
#define MAX 2187

int N;
int answer[3];
int map[MAX][MAX];

int check(int x, int y, int size, int num)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (map[x + i][y + j] != num)//size만큼 반복문을 돌려서 모두 동일하지 않다면
                return (0);//동일하지 않다고 리턴
    return (1);
}

void divide(int x, int y, int size)
{
    //만약 종이 안의 수가 동일하면
    //해당 숫자의 갯수를 업데이트
    //(map+1 해주는 이유는 -1을 인덱스로 넣을 수 없으므로
    //-1은 0번, 0은 1번, 1은 2번 인덱스에 넣어주는 방식)
    if (check(x, y, size, map[x][y]))
        answer[map[x][y] + 1]++;
    else
    {
        for (int i = 0; i < 3; i++)//4분할에서 9분할해주는 방식
            for (int j = 0; j < 3; j++)
                divide(x + i * size / 3, y + j * size / 3, size / 3);
    }
}

int main(void)
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &map[i][j]);
    
    divide(0, 0, N);
    for (int i = 0; i < 3; i++)
        printf("%d\n", answer[i]);
    return (0);
}