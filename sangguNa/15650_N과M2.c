#include <stdio.h>

int arr[11];
int check[11];
int N, M;

//n과 m 문제와 달리, 오름차순 확인을 위해 index 매개변수도 추가됨
void back_track(int cnt, int index)
{
    //cnt와 M이 같아지면 배열의 숫자들 출력
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return ;
    }
    //cnt가 M에 도달해지 못했으면 check 배열을 확인하면서 arr에 수 넣기
    //추가로 index를 저장하기 위해 매개변수로 받음
    else
    {
        for (int i = index; i < N; i++)
        {
            if (check[i] == 0)
            {
                check[i] = 1;
                arr[cnt] = i + 1;
                back_track(cnt + 1, i);
                check[i] = 0;
                arr[cnt] = 0;
            }
        }
    }
}

int main(void)
{
    scanf("%d %d", &N, &M);
    
    back_track(0, 0);

    return (0);
}