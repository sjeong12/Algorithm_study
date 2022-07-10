#include <iostream>

using namespace std;

//파도반 수열 : 예제로 주어진 수열을 잘 살펴보면 i번째 수열은 i-2 번째와 i-3번째 수열 두개의 합으로 구성됨
int t, n; //테스트 케이스, N
long long pado[101]; //파도반 수열을 저장하는 배열, int 범위를 넘어서므로 long long 으로 만듬

int main(void)
{
    pado[0] = 0;
    pado[1] = pado[2] = pado[3] = 1;

    cin >> t;

    while (t--)
    {
        cin >> n;
        
        for (int i = 4; i <= n; i++)
            pado[i] = pado[i - 2] + pado[i - 3]; //파도반 수열 점화식

        cout << pado[n] << endl;
    }

    return (0);
}