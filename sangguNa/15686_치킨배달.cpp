#include <iostream>
#include <vector>
#include <cmath>

#define MAX 50

using namespace std;

int N, M, chicken_count, answer;
int map[MAX][MAX];
bool check[13];//치킨집이 선택됐는지 체크하는 배열

vector<pair<int, int>> house, chicken, v;

int Min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int calculate_distance()
{
    int sum = 0;
    for (int i = 0; i < house.size(); i++)
    {
        int x1 = house[i].first;//i번째 집 좌표를 x1,y1에 대입
        int y1 = house[i].second;
        int d = 2147483647;

        for (int j = 0; j < v.size(); j++)
        {
            int x2 = v[j].first;//j번째 치킨집 좌표를 x2,y2에 대입
            int y2 = v[j].second;
            int dist = abs(x2 - x1) + abs(y2 - y1);

            d = Min(d, dist);//이를 통해 거리의 최솟값을 d에 넣어줌
        }
        sum = sum + d;//거리의 최솟값들을 계속 더해줌
    }
    return (sum);
}

void select_chicken(int idx, int count)
{
    if (count == M)
    {
        answer = Min(answer, calculate_distance());
        return ;
    }

    for (int i = idx; i < chicken_count; i++)
    {
        if (check[i] == true)
            continue ;
        check[i] = true;//선택중이라 표시
        v.push_back(chicken[i]);//i번째 치킨집의 좌표정보를 v에 넣어줌
        select_chicken(i, count + 1);//DFS 연산 수행
        check[i] = false;//선택한 치킨집의 연산이 끝났으면 다음을 위해 false 로 표시
        v.pop_back();//사용한 치킨집 좌표 pop
    }
}

int main(void)
{
    answer = 2147483647;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];//맵정보 입력
            if (map[i][j] == 1)
                house.push_back(make_pair(i, j));//집의 좌표 입력
            if (map[i][j] == 2)
                chicken.push_back(make_pair(i, j));//치킨집의 좌표 입력
        }
    }
    chicken_count = chicken.size();

    select_chicken(0, 0);
    cout << answer << endl;

    return (0);
}