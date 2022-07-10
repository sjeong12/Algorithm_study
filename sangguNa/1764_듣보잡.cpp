#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, M;
	string str;
	vector<string> v;//듣도 못한 사람 저장
	vector<string> v_answer;//듣도 보도 못한 사람 저장

	cin >> N >> M;
	v.resize(N);//미리 메모리를 할당하여 시간 절약 및 v[i] 로 입력받기 위해서 resize
	for (int i = 0; i < N; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());//이분 탐색을 위해 먼저 정렬

	for (int i = 0; i < M; i++)
	{
		cin >> str;
		if (binary_search(v.begin(), v.end(), str))//이분 탐색으로 중복 찾기
			v_answer.push_back(str);//중복 이름을 찾았으면 저장
	}

	sort(v_answer.begin(), v_answer.end());
	cout << v_answer.size() << endl;
	for (int i = 0; i < v_answer.size(); i++)
		cout << v_answer[i] << endl;
	
	return (0);
}