#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    int N, K;
    queue<int> q;//큐 생성

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        q.push(i);//1부터 N까지 큐에 push해줌
    
    cout << "<";
    while (!q.empty())
    {
        for (int i = 1; i <= K - 1; i++)
        {
            /*
                ex) 1 2 3 4가 입력되있고 K = 3일때, K - 1 = 2번만큼
                1, 2는 push해주고 앞의 1, 2는 pop 해줌
                결과) 3 4 1 2
            */
            q.push(q.front());
            q.pop();
        }
        //K번째 수는 출력해주고 pop해줌
        cout << q.front();
        q.pop();

        if (!q.empty())//비어있지 않다면 계속 출력하기 위해 ", "출력
            cout << ", ";
    }
    
    cout << ">" << '\n';

    return (0);
}