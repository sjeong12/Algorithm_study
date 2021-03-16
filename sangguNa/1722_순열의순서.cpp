#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long fac[21]; //1! ~ 20! 값을 저장할 배열
bool check[21]; // 1 ~ n 까지의 숫자가 순열에 있는지 없는지 확인하는 배열

int main(void)
{
    int n, cmd;

    cin >> n;

    fac[0] = 1;

    //팩토리얼 초기화
    for(int i = 1; i < 21; i++)
        fac[i] = fac[i - 1] * i;
    
    //어떤 일을 수행할지 입력
    cin >> cmd;

    if (cmd == 2) //몇 번째 수열인지 출력
    {
        vector<int> a(n);

        for (int i = 0; i < n; i++) //수열 입력
            cin >> a[i];
        
        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < a[i]; j++)
            {
                if (check[j] == false) //1부터 해당하는 원소까지 팩토리얼 값을 늘려가며 더해줌
                    ans += fac[n - i - 1];
            }
            check[a[i]] = true; //수열에 해당하는 숫자는 존재한다고 체크
        }

        cout << ans + 1 << endl;
    }
    else //k 번째 수열 출력
    {
        long long k;

        cin >> k;

        vector<int> a(n);

        for (int i = 0; i < n; i++) //k번째 순열을 찾는 과정
        {
            for (int j = 1; j <= n; j++)
            {
                if (check[j] == true) //수열에 이미 존재하는 숫자면 넘어감
                    continue;
                
                if (fac[n - i - 1] < k) //팩토리얼 값이 k보다 작으면 k에서 팩토리얼 값을 빼줌
                    k -= fac[n - i - 1];
                else
                {
                    //팩토리얼 값이 k보다 크면 해당하는 원소의 숫자를 찾은 것. 
                    //a[i]에 저장하고 순열에 존재하는 숫자를 체크해줌
                    a[i] = j;
                    check[j] = true;
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }

    return (0);
}