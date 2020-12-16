#include <stdio.h>
#include <functional>
#include <algorithm>
using namespace std;

int main(void)
{
    int num[10000], n; //문제 조건이 1 <= n <= 10,000 이므로 배열의 크기를 10,000으로 설정
    int i, j; //반복에 사용할 변수
    int tmp; //서로 바꾸기 위한 변수

    scanf("%d", &n); //사용자로부터 자릿수를 입력받음

    for(i = 0; i < n; i++)
        scanf("%d", &num[i]); //n만큼 순열을 입력받는다
    
    for(i = n - 1; i > 0; i--)
    {
        if(num[i - 1] < num[i]) //맨 뒤(i == n - 1)부터 탐색하여 오름차순이 아닌 지점(i - 1)을 확인함
        {
            for(j = n - 1; j > i - 1; j--) //찾아낸 지점(i - 1)보다 큰 수를 뒤에서부터 찾아 서로 바꿈
            {
                if(num[i - 1] < num[j])
                    break;
            }
            tmp = num[i - 1];
            num[i - 1] = num[j];
            num[j] = tmp;
            break;
        }
    }

    if(i == 0)
    {
        printf("-1\n");
        return (0);
    }
    //algorithm 헤더파일에 속해있는 sort 알고리즘
    //sort(start, end)를 이용하여 start ~ end 의 범위에 있는 인자를 오름차순으로 정렬
    //마지막 3번째 인자에 'greater<자료형>()'을 사용하면 내림차순
    //' less<자료형>()'을 사용하면 오름차순(기본값)
    sort(num + i, num + n); 

    for(i = 0; i < n; i++)
        printf("%d ", num[i]);
    
    
    return (0);
}