#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

/*
2018.10.30
순열그래프(BOJ 9463	시간초과)
두부
*/


#define MAX 100001

int arr[3][MAX];
pair<int, int>myPair[MAX];

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++)
	{
		int n;
		int key = 0;	

		scanf("%d", &n);

		for (int j = 1; j <= 2; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				scanf("%d", &arr[j][k]);
				if (j == 1)
					myPair[arr[j][k]].first = k;
				else
					myPair[arr[j][k]].second = k;
			}//for()
		}//for()
    
		for (int a = 1; a <= n; a++)
		{
			for (int b = 1; b <= n; b++)
			{
				if ((myPair[a].first > myPair[b].first&&myPair[a].second < myPair[b].second) ||
					(myPair[a].first<myPair[b].first&&myPair[a].second>myPair[b].second))
					key++;
			}//for()
		}//for()
		printf("%d\n",key / 2);
	}//for()
	return 0;
}//main()