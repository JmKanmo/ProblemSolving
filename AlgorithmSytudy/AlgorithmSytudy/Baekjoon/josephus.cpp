#include "pch.h"
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

/*
2018.10.23
조세퍼스문제(백준 1158)
두부
*/


//조세퍼스알고리즘 수행함수

void josephus(int n, int m)
{
	queue<int>q; //알고리즘에 필요한 큐

	for (int i = 1; i <= n; i++)
		q.push(i);

	cout << "<";

	while (q.size() != 0)
	{
		if (q.size() == 1)
		{
			cout << q.front() << ">";
			q.pop();
			break;
		}
		for (int i = 1; i < m; i++)
		{
			q.push(q.front());
			q.pop();
		}//for()
		cout << q.front() << ", ";
		q.pop();
	}//while()
}//josephus()

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	//조세퍼스 함수 호출
	josephus(n, m);
	return 0;
}//main()
