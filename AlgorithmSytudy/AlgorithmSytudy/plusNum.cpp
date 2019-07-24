#include "pch.h"
#include <iostream>
#include <cstdio>

using namespace std;

/*
2018.10.27
완전탐색실습
두부
*/

int N;
int cnt;

void bfs(int n)
{
	if (n>=N)
	{
		if (n == N)
			cnt++;
		return;
	}
	else
	{
		bfs(n + 1);
		bfs(n + 2);
		bfs(n + 3);
	}
}

int main()
{
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		cnt = 0;
		bfs(0);
		printf("%d\n", cnt);
	}//for()
	return 0;
}//main()