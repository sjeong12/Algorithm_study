#include <stdio.h>
#include <cstring>
#include <queue> //큐를 사용하기 위한 헤더
#include <string> //to_string(), stoi()등을 사용하기 위한 헤더

#define MAX 10000
using namespace std; //큐의 각종 함수를 사용하기위해 이름공간 사용

int Start, End; 
int eratos[MAX]; //에라토스테네스 체를 저장하는 배열, e[2] = 2가 저장된 방식.
int isvisit[MAX]; //사용했는지(방문했는지)를 저장하는 배열, 0이면 사용x, 1이면 사용o

void init_Eratos()
{
    /* 
    memset함수는 어떤 메모리의 시작점부터 연속된 범위를 어떤 값으로(바이트 단위) 모두 지정하고 싶을 때 사용하는 함수이다.
    형식 : void * memset ( void * ptr, int value, size_t num );
    ptr: 채우고자 하는 메모리의 시작 포인터(시작 주소)
    value: 메모리에 채우고자하는 값. int형이지만 내부에서는 unsigned char(1 byte)로 변환되어서 저장된다.
    num: 채우고자 하는 바이트의 수. 즉, 채우고자 하는 메모리의 크기
    */
    memset(eratos, 1, sizeof(eratos)); //먼저 전부 소수라고 초기화시킴

    eratos[0] = eratos[1] = 0; //0이랑 1은 소수가 아니므로 0으로 바꿈

    for(int i = 2; i < MAX; i++)
    {
        for(int j = 2; i * j < MAX; j++)
        {
            eratos[i * j] = 0; //i의 배수는 소수가 아니므로 0으로 바꿈
        }
    }
    memset(isvisit, 0, sizeof(isvisit)); //사용했는지(방문했는지) 확인하기위한 배열을 0으로 초기화
}

void print_sol() //정답을 출력하는 함수, 너비 우선 탐색(BFS) 알고리즘 사용
{
    queue<pair<int, int>> q; //2차원배열 좌표를 가지는 큐 생성((0,0), (1,1), ...)
    q.push(make_pair(Start, 0)); //처음입력한 start 값과 count를 푸쉬(넣음)
    isvisit[Start] = 1; //사용중이라고 설정

    while (q.empty() == 0)
    {
        int c_num = q.front().first; //큐 가장 맨앞(가장 오래된)의 정보중 첫번째를 가져와서 저장
        int count = q.front().second; ////큐 가장 맨앞(가장 오래된)의 정보중 두번째를 가져와서 저장
        q.pop(); //원소 제거

        if(c_num == End) //만약 계산한 수가 입력한 End와 같다면
        {
            printf("%d\n", count); //변환 횟수 출력
            return;
        }

        for(int i = 0; i < 4; i++) //0:천의자리, 1:백의자리... 형식으로 각각의 자리에 숫자 대입
        {
            int next_num;
            for(int j = 0; j < 10; j++) //0부터 9까지 넣어서 소수인지 확인
            {
                string s = to_string(c_num); //숫자를 문자열로 바꿔줌
                s[i] = j + '0'; //i번째 자리를 문자화한 숫자 j로 교체
                next_num = stoi(s); //문자열을 다시 숫자로 바꿔서 next_num에 넣어줌

                if(eratos[next_num] == 0) continue; //소수가 아니라면 반복문 처음르로
                if(isvisit[next_num] == 1) continue; //사용(방문)한 수라면 반복문 처음으로
                if(next_num >= 10000 || next_num < 1000) continue; //지정된 범위의 수를 넘거나 그보다 낮으면 처음으로

                isvisit[next_num] = 1; //이 과정을 통과했다면 사용했다고 표시
                q.push(make_pair(next_num, count + 1)); //그 값과 증가시킨 카운트를 큐에다 넣음
            }
        }
    }
    printf("Impossible\n"); //만약 이 과정을 다 했는데도 입력한 end가 안된다면 불가능 출력
}

int main(void)
{
    int t; //테스트케이스 갯수를 입력받을 변수

    scanf("%d", &t);

    for(int c = 1; c <= t; c++)
    {
        init_Eratos(); //에라토스테네스의 체를 이용해 소수 초기화
        scanf("%d %d", &Start, &End);
        print_sol(); //정답을 출력하기위해 수행
    }
}
/*
    문제 풀이 흐름
    - 에라토스테네스의 체로 1000부터 10000까지의 소수를 구해주고
    - 큐를 이용해(BFS 알고리즘) 다음 소수 탐색, 찾으면 카운트 증가
    - 만약 입력한 End에 도달하면 카운트 출력
*/