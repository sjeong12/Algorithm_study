#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int N;

	cin >> N;
	vector<int> origin(N);
	for (int i = 0; i < N; i++)
		cin >> origin[i];
	
	vector<int> copy(origin);//원본 벡터를 복사한 벡터
	sort(copy.begin(), copy.end());//복사본 벡터 정렬
	copy.erase(unique(copy.begin(), copy.end()), copy.end());//중복 제거

	for (int i = 0; i < N; i++)
	{
		//원본 벡터의 i번째 원소가 복사본에선 몇번째에 있는지 확인(lower_bound의 반환값은 주소값)
		auto it = lower_bound(copy.begin(), copy.end(), origin[i]);
		cout << it - copy.begin() << ' ';
	}
	return (0);
}