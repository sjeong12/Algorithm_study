#include <iostream>

using namespace std;

int A, B, V;
int answer = 0;
int day, almost, howmany;

int main(void)
{
    cin >> A >> B >> V;

    if (A == V)
    {
        cout << 1 << endl;
        return (0);
    }
    day = A - B;
    almost = V - A;
    if (almost % day)
        howmany = (almost / day) + 1;
    else
        howmany = almost / day;
    answer = howmany + 1;

    cout << answer << endl;
    return (0);
}