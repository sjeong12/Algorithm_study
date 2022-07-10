#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> pib;

int main(void)
{
    int N, x;
    cin >> N;
    //push되면 삽입후 우선순위에따라 정렬
    //pop되면 삭제후 정렬
    //3번째 인자에 greater<>을 주면 오름차순으로 정렬됨
    priority_queue<pib, vector<pib>, greater<pib>> pq;

    while (N--)
    {
        cin >> x;
        if (x == 0)
        {
            if (!pq.empty())//비어있지않다면 top 출력
            {
                cout << pq.top().second << "\n";
                pq.pop();
            }
            else
                cout << "0\n";
        }
        else
            pq.push({abs(x), x});//절댓값 및 원본 수를 같이 삽입
    }
    return (0);
}