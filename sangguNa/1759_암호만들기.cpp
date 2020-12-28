#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int l; //L 개로 이루어진 암호문
int c; //c 개로 주어져있는 문자
int input[16]; //문자를 입력받고 정수로 바꿈 (임시저장소)
char str[16]; //정렬된 input 배열값들을 문자로 바뀐후 저장되는 배열

bool check[16]; //사용여부를 저장하는 배열

void dfs(int a, int cnt, int ja, int mo) //a:현재 위치, cnt:깊이, dfs를 수행한 횟수, ja:자음 갯수, mo:모음 갯수
{
    if (cnt == l) //입력값으로 제시한 길이와 같으면
    {
        if (ja < 2 || mo < 1) //자음 2개이상, 모음 1개이상 조건을 충족 안하면 중지
            return;
        for (int i = 0; i < c; i++) //충족하면 check를 확인해서 문자열 출력
        {
            if (check[i] == 1)
                cout << str[i];
        }
        cout << "\n";
        return ;
    }

    for (int i = a; i < c; i++)
    {
        if (check[i] == 0) //사용중이 아니라면 사용중으로 바꿔서 진행
        {
            check[i] = 1;
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            {
                dfs(i + 1, cnt + 1, ja, mo + 1); //현재 위치가 모음이라면 모음 갯수를 증가시켜서 dfs 수행
            }
            else
            {
                dfs(i + 1, cnt + 1, ja + 1, mo); //그외 자음이라면 자음 갯수를 증가시켜서 dfs 수행
            }
            check[i] = 0; //사용중인 문자라면 사용중이 아님으로 바꿔줌
        }
    }
}

int main(void)
{
    cin >> l >> c; //암호문이 몇자로 이루어져있는지, 몇개의 문자를 입력받을건지 입력받음
    
    for (int i = 0; i < c; i++)
    {
        char al;
        cin >> al;
        input[i] = al - 'a'; //입력받은 문자열을 정수로 바꿔서 저장
    }

    sort(input, input + c); //오름차순으로 정렬
    for (int i = 0; i < c; i++)
    {
        str[i] = input[i] + 'a'; //정수를 다시 문자로 바꿔서 저장
    }

    dfs(0, 0, 0, 0); //dfs 수행

    return (0);
}