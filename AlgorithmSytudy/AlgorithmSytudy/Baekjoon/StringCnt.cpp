#include <iostream>
#include <string>

using namespace std;

/*
2018.11.11
단어의개수(BOJ 1152)
두부
*/

#define MAX 1000001

char arr[MAX];

int main()
{
	string str;
	int space = 0;
	int i = 0;

	getline(cin, str);

	for (i = 0; i < str.size(); i++) arr[i + 1] = str[i];
	arr[i + 1] = '\n';


	for (int i = 0; i < MAX; i++)
	{
		if (arr[i] == '\n')
			break;
		if ((arr[i] == NULL || arr[i] == 32) && (arr[i+1] >= 65 && arr[i+1] <= 122))
			space++;
	}//for()

	printf("%d\n", space);
	return 0;
}//main()