#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef struct	s_student
{
	string name;
	int kor, eng, math;
}				t_student;

bool	comp(t_student s1, t_student s2)
{
	if (s1.kor == s2.kor && s1.eng == s2.eng && s1.math == s2.math)
		return (s1.name < s2.name);//오름차순
	else if (s1.kor == s2.kor && s1.eng == s2.eng)
		return (s1.math > s2.math);//내림차순
	else if (s1.kor == s2.kor)
		return (s1.eng < s2.eng);
	else
		return (s1.kor > s2.kor);
}

int main(void)
{
	int N;
	cin >> N;

	vector<t_student> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
	
	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < N; i++)
		cout << v[i].name << '\n';//endl 키워드가 시간 많이 잡아먹는 듯함
	
	return (0);
}