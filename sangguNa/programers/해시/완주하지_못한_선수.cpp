#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;
    
    for (auto c : completion)
        m[c] += 1;
    
    for (auto p : participant)
    {
        m[p] -= 1;
        if (m[p] < 0)
            return p;
    }
}

/*
    범위기반 for문
    for (element_declaration : array)
        statement;
    element_declaration은 배열 요소와 같은 자료형을 가져야 하므로,
    auto 키워드를 사용해서 C++이 자료형을 추론하도록 하는 것이 이상적이다.
*/