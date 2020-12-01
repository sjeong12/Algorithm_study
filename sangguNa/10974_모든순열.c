#include <stdio.h>

int n; //몇개의 순열로 만들건지 입력받는 변수
int num[8]; //1부터 n까지의 순열이 초기화되어 저장되는 배열
int permu[8]; //모든 순열이 저장되어 출력되는 배열
int check[8]; //배열 num을 순회하면서, 사용된 곳은 1로 체크

void print_permu(int a) //순열을 재배열 및 출력하는 함수
{
    if(a == n) //만약 입력된 n과 조합된 순열의 길이가 같아진다면
    {
        for(int i = 0; i < n; i++)
        {
            printf("%d ", permu[i]); //순열을 출력
        }
        printf("\n");
        return ;
    }

    for(int i = 0; i < n; i++) //하나하나 순열을 넣어서 조합
    {
        if(check[i] != 1) //사용된 num이 아니라면
        {
            permu[a] = num[i]; //num을 순열에 넣음
            check[i] = 1; //num을 사용하므로 check를 1로 설정
            print_permu(a + 1); //다음 숫자를 집어넣음
            check[i] = 0; //끝나면 check를 0으로 설정
        }
    }
    return ;
}

int main(void)
{
    int i = 0;

    scanf("%d", &n); //순열의 길이 n을 입력받음
    
    while(i < n)
    {
        num[i] = i + 1; //0번째 인덱스부터 1부터 n까지의 숫자를 넣음
        check[i] = 0; //check 초기화
        i++;
    }

    print_permu(0); //순열 만들기 및 출력

    return (0);
}