#include <stdio.h>

//dp를 활용해서 해결하는 문제
int m, n; //m, n의 크기를 입력받음
int m_data[1001][1001]; //사탕의 갯수가 저장되어있는 배열
int c_max_data[1001][1001]; //그 좌표에서의 사탕 갯수의 최댓값이 저장되어있는 배열
//ex) c_max_data[a][b] = c : (a, b) 좌표에서의 사탕의 최대갯수는 c개

int compare(int a, int b, int c) //3개를 비교해서 가장 큰 값을 리턴
{
    int max = 0; //중요, 초기화 제대로 안하면 메모리값을 반환함
    if(max < a) max = a;
    if(max < b) max = b;
    if(max < c) max = c;

    return max;
}

int main(void)
{
    scanf("%d %d", &m, &n);

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &m_data[i][j]); //사탕 갯수를 각 배열위치에 저장
        }
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            /*
                1 2
                5 (a,b) 상태일 때, 1+(a,b), 2+(a,b), 5+(a,b)중 사탕갯수의 최대값은 5+(a,b)임
                즉, 이전좌표들 (a-1,b-1), (a, b-1), (a-1,b) 중 가장 큰 값과 현재좌표(a,b)의 값을 더하면
                최대값이 됨.
                이에 따라 점화식을 구하면 다음과 같다.
            */
            c_max_data[i][j] = compare(c_max_data[i - 1][j], c_max_data[i][j - 1], c_max_data[i - 1][j - 1]) + m_data[i][j];
        }
    }
    int max = c_max_data[m][n];
    printf("%d\n", max);

    return(0);
}