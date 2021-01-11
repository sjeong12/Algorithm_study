#include <iostream>
#include <vector>
using namespace std;

int input;
int st = 0, en = 0;
int sum = 0;
int ans = 0;
vector<int> prime;

int main(void)
{
    cin >> input;

    vector<int> eratos(input + 1, 1); //input + 1 개의 원소를 1로 초기화시켜서 만듬
    
    eratos[0] = eratos[1] = 0; //0이랑 1은 소수가 아니므로 0으로 바꿈

    for(int i = 2; i <= input; i++)
    {
        for(int j = 2; i * j <= input; j++)
        {
            eratos[i * j] = 0; //i의 배수는 소수가 아니므로 0으로 바꿈
        }
    }

    for (int i = 2; i <= input; i++)
    {
        if (eratos[i] == 1)
            prime.push_back(i);
    }

    while (1)
    {
        if (sum > input) //입력값보다 sum이 크면
        {
            sum = sum - prime[st]; //왼쪽 포인터 이동
            st++;
        }
        else if (sum < input) //입력값보다 sum이 작으면
        {
            if (en >= prime.size()) //만약 오른쪽 포인터가 벡터 사이즈보다 크면 반복문 종료
                break;
            sum = sum + prime[en]; //오른쪽 포인터 이동
            en++;
        }
        else //입력값이랑 sum이 같으면
        {
            ans++; //갯수 증가시키고
            if (en >= prime.size()) //만약 오른쪽 포인터가 벡터 사이즈보다 크면 반복문 종료
                break;
            sum = sum + prime[en]; //오른쪽 포인터 이동
            en++;
        }
    }

    cout << ans << endl; //경우의 수 출력

    return (0);
}