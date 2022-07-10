#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(void)
{
	string doc, search;
	int cnt = 0;

	getline(cin, doc);
	getline(cin, search);
	
	for (int i = 0; i < doc.length(); i++)
	{
		bool flag = true;
		for (int j = 0; j < search.length(); j++)
		{
			if (doc[i + j] != search[j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cnt += 1;
			i += search.length() - 1;
		}
	}

	cout << cnt << '\n';
	return (0);
}