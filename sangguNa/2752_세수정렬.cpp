#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int num[3];

	for (int i = 0; i < 3; i++)
		cin >> num[i];
	
	sort(num + 0, num + 3);
	
	for (int i = 0; i < 3; i++)
        cout << num[i] << " ";
	cout << endl;
}