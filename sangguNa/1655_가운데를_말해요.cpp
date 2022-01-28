#include <iostream>
#include <queue>
using namespace std;

/*
중간 값 구하기 알고리즘
1. 최대 힙의 크기는 최소 힙의 크기와 같거나, 하나 더 크다.
2. 최대 힙의 최대 원소는 최소 합의 최소 원소보다 작거나 같다.
이때 알고리즘에 맞지 않다면 최대 힙, 최소 힙의 가장 위의 값을 swap해준다.
*/

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, input, size;
    int max_val, min_val;
    cin >> N;
    priority_queue<int> max;//max 큐의 top에는 작은 값들 중에 최댓값이 들어간다.
    priority_queue<int, vector<int>, greater<int>> min;//min 큐의 top에는 큰 값들 중에 최솟값이 들어간다.

    while (N--)
    {
        cin >> input;
        if (max.size() == min.size())//max 의 size는 min보다 같거나 커야함
            max.push(input);
        else
            min.push(input);
        //만약 max의 탑이 min의 탑보다 크면
        //최대 힙의 최대 원소는 최소 합의 최소 원소보다 작거나 같다.
        //의 규칙을 위배하므로 서로 swap한다
        if (!max.empty() && !min.empty() && (max.top() > min.top()))
        {
            max_val = max.top();
            min_val = min.top();
            max.pop();
            min.pop();
            max.push(min_val);
            min.push(max_val);
        }
        cout << max.top() << "\n";
    }
}