#include <iostream>
#include <string>

using namespace std;

/*
2018.11.10
���ýǽ�(BOJ 10799)
�κ�
*/

int main()
{
	string str;
	int front = 0, end = 0;
	int ans = 0;

	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
			front++;	
		else {
			front--;
			ans += str[i - 1] == ')' ? 1 : front;
		}
	}//for()
	printf("%d\n", ans);
	return 0;
}//main()