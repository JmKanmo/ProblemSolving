#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

/*
2018.11.11
�Է¹���������(BOJ 11718)
�κ�
*/

int main()
{
	string str;

	int len = 0;

	while (true)
	{
		if (++len > 100)
			break;
		getline(cin, str);
		cout << str << endl;
	}
	return 0;
}//main()
