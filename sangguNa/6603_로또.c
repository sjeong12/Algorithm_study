#include <stdio.h>

//이게 백트래킹 문제라 하네

int k; //집합의 길이
int s[13]; //입력된 로또번호가 들어간 집합
int s_result[13]; //6개의 로또번호가 들어가있는 집합

void print_roto(int start, int d) //로또번호를 선택하고 출력하는 함수, i의 시작점과 깊이 d를 인자로 가짐
{   
    int i; //반복자 i 선언

    if(d == 6) //번호 6개가 선택됐다면
    {
        for(int i = 0; i < 6; i++)
        {
            printf("%d ", s_result[i]); //출력
        }
        printf("\n");
    }
    else
    {
        for(i = start; i < k; i++) //i = 0이 아닌 i = start로 이루어져있다.
        {
            s_result[d] = s[i]; //ex) d=5 일때 i=5, i=6이 들어갈 수 있음
            print_roto(i + 1, d + 1); //i(start) 와 d를 증가시키면서 재귀함수 호출
        }
    }
    
}

int main(void)
{
    while(1)
    {
        scanf("%d", &k);

        if(k == 0)
            break; //0이 입력되면 입력 종료

        for(int i = 0; i < k; i++)
        {
            scanf("%d", &s[i]);
        }

        print_roto(0, 0); //기존 dfs와 달리 이번에 인자를 2개 줌
        printf("\n");
    }

    return(0);
}