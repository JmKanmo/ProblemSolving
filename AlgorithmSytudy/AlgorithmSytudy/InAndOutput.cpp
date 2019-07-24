#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

/*
2018.11.11
입력받은대로출력(BOJ 11718)
두부
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
