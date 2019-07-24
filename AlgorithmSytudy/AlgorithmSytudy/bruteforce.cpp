#include "pch.h"
#include <iostream>
#include <cstdio>

using namespace std;

/*
2018.10.27
����Ž���ǽ�
�κ�
*/

#define MAX 21

int N, SUM, cnt;
int arr[MAX];


//����Ž������ �Լ�(���ȣ��)
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

