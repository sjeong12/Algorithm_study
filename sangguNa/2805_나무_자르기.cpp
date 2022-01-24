#include <iostream>
#include <algorithm>
using namespace std;

int N, M;//N:나무의 수, M:집으로 가져가려하는 나무의 수
int tree[1000001];
long long sum, ans;
long long HEIGHT = 1000000000;

void get_height(long long front, long long h)
{
    if (front <= h)
    {
        long long mid = (front + h) / 2;
        sum = 0;
        for (int i = 1; i <= N; i++)
        {
            if (tree[i] > mid)//나무가 지정 높이보다 크다면
                sum += tree[i] - mid;//그 차이만큼 자르고 더해줌
        }
        if (sum >= M)//잘라낸 나무길이 합이 가져가려는 길이보다 크거나같으면
        {
            ans = mid;//현재 설정 높이값을 ans에 저장
            get_height(mid + 1, h);//높이를 좀 더 높여보기위해 탐색
        }
        else
            get_height(front, mid - 1);//너무 높였으므로 낮춰서 탐색
    }
}

int main(void)
{
    scanf("%d %d", &N, &M);
    
    for (int i = 1; i <= N; i++)
        scanf("%d", &tree[i]);
    
    sort(tree + 1, tree + 1 + N);//이분 탐색을 위해 정렬부터 함
    get_height(0, HEIGHT);
    printf("%lld\n", ans);

    return (0);
}