#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		int n;
		pair<int, int> p[100001];

		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> p[i].first >> p[i].second;//숫자가 작을수록 높은 성적
		
		sort(p, p + n);//서류 성적으로 오름차순 정렬
		int ans = 1;//맨 처음 사람은 무조건 채용되므로 1부터 시작
		int temp = p[0].second;//면접 성적 저장
		for (int i = 1; i < n; i++)
		{
			if (p[i].second < temp)//앞사람보다 면접 성적이 좋으면
			{
				ans++;
				temp = p[i].second;
				if (temp == 1)//가장 작은 숫자가 되었다면 이 사람보다 면접점수가 높은 사람이 없으므로 break;
					break;
			}
		}
		cout << ans << '\n';
	}
	return (0);
}