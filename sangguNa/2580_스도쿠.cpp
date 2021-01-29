#include <iostream>

#define MAX 9
using namespace std;

int map[MAX][MAX];
bool row[MAX][MAX]; //row[a][b] = true : a번째 가로줄에서 b라는 숫자는 이미 존재합니다.
bool col[MAX][MAX]; //col[a][b] = true : a번째 세로줄에서 b라는 숫자는 이미 존재합니다.
bool square[MAX][MAX]; //square[a][b] = true : a번째 사각형에 b라는 숫자는 이미 존재합니다.
/*
    몇 번째 사각형인지는 어떻게 알아냄?
    (0, 0) 0번, (0, 3) 1번, (0, 6) 2번 ...
    (3, 0) 3번, (6, 0) 6번, (7, 7) 8번 ...
    이런 규칙을 이용해서 식을 구하면 (row / 3) * 3 + (col / 3)이 나온다함..
*/

void print()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void DFS(int cnt) //스도쿠 빈칸(0) 을 채우는 함수
{
    int x = cnt / MAX; //x좌표
    int y = cnt % MAX; //y좌표

    if (cnt == 81) //스도쿠 81칸을 다 채웠다면 (0 ~ 80)
    {
        print(); //0을 채운 스도쿠 판 출력
        exit(0);
    }

    if (map[x][y] == 0) //0인곳을 발견하면
    {
        for (int i = 1; i <= 9; i++)
        {
            //해당 칸에서 숫자를 사용할때, 사용되지 않은 숫자라면 수행
            if (row[x][i] == false && col[y][i] == false && square[(x / 3) * 3 + (y / 3)][i] == false)
            {
                row[x][i] = true;
                col[y][i] = true;
                square[(x / 3) * 3 + (y / 3)][i] = true;
                map[x][y] = i;

                DFS(cnt + 1);

                map[x][y] = 0;
                row[x][i] = false;
                col[y][i] = false;
                square[(x / 3) * 3 + (y / 3)][i] = false;
            }
        }
    }
    else //아니라면 그냥 cnt + 1
        DFS(cnt + 1);
}

int main(void)
{
    for (int i = 0; i < MAX; i++) //입력값을 받는 부분
    {
        for (int j = 0; j < MAX; j++)
        {
            cin >> map[i][j];
            if (map[i][j] != 0) //0이 아닌 숫자가 들어오면 숫자가 채워졌다고 처리
            {
                row[i][map[i][j]] = true; //행, 열 ,사각형 모두 해당 숫자가 사용중이라고 표시
                col[j][map[i][j]] = true;
                square[(i / 3) * 3 + (j / 3)][map[i][j]] = true;
            }
        }
    }

    DFS(0); //풀이 과정 수행

    return (0);
}