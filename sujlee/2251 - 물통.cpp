#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct	Water
{
	int a, b, c;
};

int	main()
{
	int				bucket[3];				//물통 용량
	bool			visit[201][201][201];	//a,b,c값의 방문 여부
	queue<Water>	q;						//bfs용 queue
	vector<int>		res;					//출력할 값

	//입력 및 초기화
	scanf("%d %d %d", &bucket[0], &bucket[1], &bucket[2]);
	memset(visit, false, sizeof(visit));
	//풀이 - visit을 이용해 중복을 피하며, bfs로 가능한 abc의 모든 경우의 수를 탐색
	q.push({0, 0, bucket[2]});
	while (!q.empty())
	{
		int a = q.front().a;	//현재 a,b,c 물의 양
		int b = q.front().b;
		int c = q.front().c;
		q.pop();
		if (visit[a][b][c])	//이미 방문한 곳은 패스 
			continue;
		visit[a][b][c] = true;
		if (a == 0)	//a가 비었을 때, c값을 result값에 포함
			res.push_back(c);
		//다음으로 있을 수 있는 경우의 수 6가지를 모두 큐에 포함시킨다
		if (a + b > bucket[1])	//a -> b
			q.push({a + b - bucket[1], bucket[1], c});
		else
			q.push({0, a + b, c});
		if (a + c > bucket[2])	//a -> c
			q.push({a + c - bucket[2], b, bucket[2]});
		else
            q.push({0, b, a + c}); 
		if (a + b > bucket[0])	//b -> a
			q.push({bucket[0], a + b - bucket[0], c});
		else
			q.push({a + b, 0, c});
		if (b + c > bucket[2])	//b -> c
			q.push({a, b + c - bucket[2] , bucket[2] });
		else
			q.push({a, 0, b + c});
		if (b + c > bucket[1])	//c -> b
			q.push({a, bucket[1], b + c - bucket[1]});    
		else
			q.push({a, b + c, 0 });     
		if (a + c > bucket[0])	//c -> a
			q.push({bucket[0], b, a + c - bucket[0] });
		else
			q.push({a + c, b, 0});
	}
	//얻은 res값을 정렬하여 출력
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++)
		printf("%d ", res[i]);
	return (0);
}