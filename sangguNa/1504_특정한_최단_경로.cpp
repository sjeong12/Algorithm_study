//최단경로 분류
#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int N, E, A, B, ans;
int dist[810];
vector<pair<int, int> > vec[810];

int Min(int A, int B)
{
	if (A < B)
		return (A);
	return (B);
}

void dijkstra(int start)
{
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (pq.empty() == 0)//큐가 비어있지않으면 반복
	{
		//우선순위큐를 최소힙으로 구현하려면 값을넣고 빼는 연산을 할 때 -를 붙임
		//값이 클 수록 더 높은 우선순위를 가지므로, (2, 3, 5)같이 작은 수부터 사용하게하려면
		//-를 붙여서 (-2, -3, -5)가 들어가도록 해야함
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < vec[cur].size(); i++)
		{
			int next = vec[cur][i].first;
			int ncost = vec[cur][i].second;
			if (dist[next] > cost + ncost)
			{
				dist[next] = cost + ncost;//다음 방문 노드의 거리값 갱신
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
}

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> E;
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back(make_pair(b, c));
		vec[b].push_back(make_pair(a, c));
	}
	cin >> A >> B;

	//N번 정점으로 갈 수있는지 판별해주는 flag들
	//2개다 false면 N번 정점까지 갈수없음을 뜻함
	bool flag1, flag2;
	flag1 = flag2 = true;

	//1번 정점에서 A정점과, B정점으로 가는데 걸리는 최단 경로를 알아내기 위한 다익스트라 탐색
	for (int i = 1; i <= N; i++)
		dist[i] = INF;
	dijkstra(1);

	int route1 = dist[A];
	int route2 = dist[B];
	if (route1 == INF)
		flag1 = false;
	if (route2 == INF)
		flag2 = false;
	
	//A정점에서 B정점으로 가는데 걸리는 최단 경로를 알아내기 위한 다익스트라 탐색
	//A->B의 거리를 알아냈다면 B->A의 거리도 알아낸 것
	for (int i = 1; i <= N; i++)
		dist[i] = INF;
	dijkstra(A);
	if (flag1 == true)
		route1 = route1 + dist[B];
	if (flag2 == true)
		route2 = route2 + dist[B];
	
	//A정점에서 N정점으로 가는데 걸리는 최단 경로를 알아내기 위한 다익스트라 탐색
	for (int i = 1; i <= N; i++)
		dist[i] = INF;
	dijkstra(B);
	if (flag1 == true)
		route1 = route1 + dist[N];
	
	//B정점에서 N정점으로 가는데 걸리는 최단 경로를 알아내기 위한 다익스트라 탐색
	for (int i = 1; i <= N; i++)
        dist[i] = INF;
    dijkstra(A);
    if (flag2 == true)
        route2 = route2 + dist[N];
	
	if (flag1 == false && flag2 == false)
		ans = -1;
	else
		ans = Min(route1, route2);
	
	if (ans >= INF || ans < 0)
		ans = -1;
	
	cout << ans << "\n";
	return (0);
}