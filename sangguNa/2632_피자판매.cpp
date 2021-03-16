#include <iostream>

using namespace std;

int k, m, n;
int pizzaA[1000], pizzaB[1000]; //pizza'I'[a] = b; : 메뉴 I 의 a번째 조각 크기는 b다.
int Acnt[2000001], Bcnt[2000001];
int result = 0;

void solve(int c, int arr[], int arrcnt[]) //피자조각 갯수, 피자조각 크기가 저장된 배열, 구매하고자 하는 피자크기를 나타내는 배열
{
    for (int i = 1; i <= c; i++)
    {
        int sum = 0;
        for (int j = 0; j < i; j++)
            sum = sum + arr[j];
        arrcnt[sum]++;

        if (sum == k) //피자 조각 크기 합이 구매하고자 하는 피자크기라면 result++
            result++;

        if (i == c) //i가 피자조각 갯수와 일치하게 되면 반복문 멈춤
            break;

        for (int j = 1; j < c; j++)
        {
            sum = sum - arr[j - 1]; //이전 값을 빼고 다음 값을 더하는 방식?
            sum = sum + arr[(j + i - 1) % c];
            
            arrcnt[sum]++;

            if (sum == k) //마찬가지로 피자 조각 크기 합이 구매하고자 하는 피자크기라면 result++
                result++;
        }
    }
}

int main(void)
{
    cin >> k >> m >> n;

    for (int i = 0; i < m; i++)
        cin >> pizzaA[i];
    
    for (int i = 0; i < n; i++)
        cin >> pizzaB[i];

    solve(m, pizzaA, Acnt);
    solve(n, pizzaB, Bcnt);

    for (int i = 1; i < k; i++)
    {
        int j = k - i;
        result = result + (Acnt[i] * Bcnt[j]);
    }

    cout << result << endl;
}