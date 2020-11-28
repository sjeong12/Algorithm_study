#include <iostream>
#include <vector> //일종의 자동으로 동적할당해주는 배열을 사용하기 위한 헤더
#include <algorithm> //sort를 사용하기위해 사용
#include <cmath> //abs 등 수학함수를 이용하기위해 사용
using namespace std; //이렇게 해주면 보다 쉽게 vector 이용 가능

vector<int> v; //비어있는 vector v 선언
int n; //입력받는 n을 다른 함수에서도 사용할 수 있게 전역변수로 선언

int Check() //수열의 절대값의 합을 구하는 함수
{
    int answer = 0; //초기값
    for(int i = 0; i < n - 1; i++)
    {
        answer = answer + abs(v[i] - v[i + 1]); //두 인자값의 차이의 절대값을 구하고 answer에 더해줌
    }
    return answer; //answer을 리턴함
}

int main(void)
{
    scanf("%d", &n); //몇개의 수열을 입력받을건지 n을 입력받음

    for(int i = 0; i < n; i++)
    {
        int tmp; //v.push_back에다 넣어주기위한 변수의 임시저장소
        scanf("%d", &tmp); //수열 인자 하나를 입력받음
        v.push_back(tmp); //입력받은 인자를 v에 넣어줌
    }
    sort(v.begin(), v.end()); //오름차순으로 정렬

    int answer = 0; //answer 초기값을 0으로 해줌
    do //최초 한번, 다음 과정을 수행하고, while 조건에 따라 계속 수행함
    {
        int check = Check(); //Check 함수의 리턴값을 변수 check에 넣어줌
        answer = max(answer, check); //answer과 check를 비교해 큰 것을 answer에 넣어줌.
    } while (next_permutation(v.begin(), v.end())); //다음 순열을 구성하고 앞의 과정을 반복함

    printf("%d", answer); //가장 큰 answer을 출력하고 프로그램 종료

    return(0);
}