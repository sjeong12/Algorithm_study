#include <stdio.h>

int arr[9];
int check[9];
int N, M;

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
    else
    {
        for (int i = index; i <= N; i++)
        {
                arr[cnt] = i;
                back_track(cnt + 1, index);
        }
    }
}

int main(void)
{
    scanf("%d %d", &N, &M);
    
    back_track(0, 1);

    return (0);
}