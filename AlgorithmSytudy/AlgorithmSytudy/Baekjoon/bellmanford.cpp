#include "pch.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 501
#define INF 987654321

typedef pair<int, int> Pair;

vector<Pair>GP_Vector[MAX];
int upper[MAX];


bool bellman_ford(int N)
{
	bool updated = false;

	upper[1] = 0;

	for (int i = 0; i < N; i++)
	{
		updated = false;

		for (int here = 1; here <= N; here++)
		{
			for (auto vertex : GP_Vector[here])
			{
				int next = vertex.first;
				int cost = upper[here] + vertex.second;

				if (upper[next] > cost)
				{
					upper[next] = cost;
					updated = true;
				}
			}//for()
		}//for()
		if (!updated)
			break;
	}//for()
	return updated == true ? true : false;
}//bellman_ford()

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		GP_Vector[A].push_back(Pair(B, C));
	}//for()

	fill(upper, upper + MAX, INF);

	if (bellman_ford(N))
		printf("-1");
	else {
		for (int i = 1; i < N; i++)
		{
			if (upper[i + 1] == INF)
				printf("-1\n");
			else
				printf("%d\n", upper[i + 1]);
		}
	}
	return 0;
}//main()
