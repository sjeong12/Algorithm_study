#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, M;

	cin >> N;
	vector<int> card(N);//상근이가 가지고 있는 카드들
	for (int i = 0; i < N; i++)
		cin >> card[i];
	
	cin >> M;
	vector<int> check(M);//가지고있는 카드인지 아닌지 체크할 숫자들
	vector<int> result(M);//결과저장용
	for (int i = 0; i < M; i++)
		cin >> check[i];
	
	sort(card.begin(), card.end());//오름차순 정렬
	for (int i = 0; i < M; i++)//이분탐색
	{
		int r = N - 1;//배열 오른쪽 끝
		int l = 0;//배열 왼쪽끝

		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (card[mid] == check[i])
			{
				result[i] = 1;
				break;
			}
			if (card[mid] > check[i])//mid값이 비교값보다 크면
				r = mid - 1;//오른쪽 위치를 조정
			else //(card[mid] <= check[i])
				l = mid + 1;
		}
	}

	for (int i = 0; i < M; i++)
	cout << result[i] << " ";
	cout << endl;
}

//실패한 코드
// int main(void)
// {
// 	int N, M;

// 	cin >> N;
// 	vector<int> card(N);//상근이가 가지고 있는 카드들
// 	for (int i = 0; i < N; i++)
// 		cin >> card[i];
	
// 	cin >> M;
// 	vector<int> check(M);//가지고있는 카드인지 아닌지 체크할 숫자들
// 	vector<int> result(M);//결과저장용
// 	for (int i = 0; i < M; i++)
// 		cin >> check[i];
	
// 	for (int i = 0; i < N; i++)
// 	{
// 		for (int j = 0; j < M; j++)
// 		{
// 			if (card[i] == check[j])
// 			{	
// 				result[j] = 1;
// 				break;
// 			}
// 		}
// 	}

// 	for (int i = 0; i < M; i++)
// 		cout << result[i] << " ";
// 	cout << endl;
// }