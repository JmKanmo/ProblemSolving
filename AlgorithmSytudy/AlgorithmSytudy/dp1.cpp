#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

/*
2018.10.27
dp실습1
두부
*/

#define MAX 100001

int main()
{
	int dp[MAX];

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &dp[i]);

	int max_N = dp[0];
	int temp = dp[0];

	for (int i = 1; i < n; i++) {
		max_N = max(max_N + dp[i], dp[i]);
		temp = max(temp, max_N);
	}//for()
	printf("%d", temp);
	return 0;
}//main()