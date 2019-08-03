#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

/*
2018.10.28
dp실습(RGB거리) - 동적계획법 성공
두부
*/

#define MAX 1001

int dp[MAX][4];


int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 3; j++)
			scanf("%d", &dp[i][j]);

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			if (j == 1)
				dp[i][j] += min(dp[i - 1][j + 1], dp[i - 1][j + 2]);
			else if (j == 2)
				dp[i][j] += min(dp[i - 1][j - 1], dp[i - 1][j + 1]);
			else
				dp[i][j] += min(dp[i - 1][j - 2], dp[i - 1][j - 1]);
		}//for()
	}//for()

	printf("%d\n", min(dp[n][1], min(dp[n][2], dp[n][3])));

	return 0;
}//main()

