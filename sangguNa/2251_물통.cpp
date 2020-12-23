#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int A, B, C; //각각 물통의 최대 용량을 입력받음
bool visit[201][201][201]; 
//중복탐색 방지를 위한 배열, visit[a][b][c] = true 의 의미는 'A물통에 a리터, B물통에 b리터, C물통에 c리터가
//들어있을 때는 이미 탐색했음' 이라는 의미임

vector<int> v;

int main(void)
{
    scanf("%d %d %d", &A, &B, &C);

    queue<pair<pair<int, int>, int>> Q;
    Q.push(make_pair(make_pair(0, 0),C));

    while (Q.empty() == 0)
    {
        int a = Q.front().first.first;
        int b = Q.front().first.second;
        int c = Q.front().second;
        Q.pop();

        if(visit[a][b][c] == true)
            continue;
        visit[a][b][c] = true;

        if(a == 0)
            v.push_back(c);
        
        //A물통에서 B물통으로 옮길때
        if(a + b > B) //B물통의 용량보다 많을때, 즉 넘치는 경우
            Q.push(make_pair(make_pair(a + b - B, B), c)); // a=3, b=7, B의 용량이 8일때 넘치므로 a = 3 + 7 - 8 = 2리터가 a에 남음
        else
            Q.push(make_pair(make_pair(0, a + b), c)); //a와 b의 합을 B물통에 넣음

        //A물통에서 C물통으로 옮길때
        if(a + c > C)
            Q.push(make_pair(make_pair(a + c - C, b), C));
        else
            Q.push(make_pair(make_pair(0, b), a + c));
        
        //B물통에서 A물통으로 옮길때
        if(b + a > A)
            Q.push(make_pair(make_pair(A, b + a - A), c));
        else
            Q.push(make_pair(make_pair(b + a, 0), c));

        //B물통에서 C물통으로 옮길때
        if(b + c > C)
            Q.push(make_pair(make_pair(a, b + c - C), C));
        else
            Q.push(make_pair(make_pair(a, 0), b + c));

        //C물통에서 A물통으로 옮길때
        if(c + a > A)
            Q.push(make_pair(make_pair(A, b), c + a - A));
        else
            Q.push(make_pair(make_pair(c + a, b), 0));
        
        //C물통에서 B물통으로 옮길때
        if(c + b > B)
            Q.push(make_pair(make_pair(a, B), c + b - B));
        else
            Q.push(make_pair(make_pair(a, c + b), 0));
    }
    sort(v.begin(), v.end()); //오름차순으로 정령
    for (int i = 0; i < v.size(); i++)
    {
        printf("%d ", v[i]); //첫 번째 물통(용량이 A인)이 비어 있을 때, 세 번째 물통(용량이 C인)에 담겨있을 수 있는 물의 양 출력
    }
    printf("\n");

    return (0);
}