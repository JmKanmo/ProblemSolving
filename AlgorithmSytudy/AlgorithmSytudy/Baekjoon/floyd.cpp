#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

/*
2018.10.21
플로이드 알고리즘실습
백준 11404번문제(플로이드)
*/

#define MAX 987654321 //임의로 만든 절대 나올 수 없는값

int dist[101][101]; // 모든정점쌍의 최단경로를 저장할 2차원배열


// 모든쌍의 최단경로를 계산하는 플로이드함수
void floyd(int n)
{
 //3중 for문을 수반한 동적계획법을 수행해 모든 정점쌍의 최단경로를 구함	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);	
}//floyd()

int main()
{
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);


	fill(&dist[0][0], &dist[0][0] + 101 * 101, MAX); // 절대 나올 수 없는값으로 다 채움

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		dist[a][b] = dist[a][b] > c ? c : dist[a][b];
	}//for()

	// 자기자신으로 가는 경로는 0으로 설정
	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;


	//플로이드함수호출
	floyd(n);

	//결과값 출력
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] == 0 || dist[i][j] == MAX)
				printf("0 ");
			else
				printf("%d ", dist[i][j]);

		}//for()
		printf("\n");
	}//for()
	return 0;
}//main()
