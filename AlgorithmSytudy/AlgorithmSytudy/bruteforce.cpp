#include "pch.h"
#include <iostream>
#include <cstdio>

using namespace std;

/*
2018.10.27
완전탐색실습
두부
*/

#define MAX 21

int N, SUM, cnt;
int arr[MAX];


//완전탐색수행 함수(재귀호출)
void dfs(int n, int sum)
{
	if (n == N)
	{
		if (sum == SUM)
			cnt++;
	}
	else
	{
		dfs(n + 1, sum + arr[n]);
		dfs(n + 1, sum);
	}
}//dfs()

int main()
{
	scanf("%d %d", &N, &SUM);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	dfs(0, 0);
	if (SUM == 0) cnt--;
	return 0;
}//main()

