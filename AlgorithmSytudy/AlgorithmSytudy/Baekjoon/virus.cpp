#include "pch.h"
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

queue<int>q;//bfs를 위한 큐
int gp[101][101]; //인접행렬(그래프) 표현
int visit[101]; //방문여부저장배열
int cnt;
int V;

//깊이우선탐색(DFS) 함수
void dfs(int v)
{
	for (int i = 1; i <= V; i++)
	{
		if (visit[i] != 0 || gp[v][i] == 0)
			continue;
		visit[i] = 1;
		cnt++;
		dfs(i);
	}//for()
}//dfs()


//너비우선탐색(bfs) 함수
void bfs(int v)
{
	visit[v] = 1;
	q.push(v);

	while (q.empty() != true)
	{
		int vertex = q.front();
		q.pop();

		for (int i = 1; i <= V; i++)
		{
			if (gp[vertex][i] == 0 || visit[i] == 1)
				continue;

			cnt++;
			visit[i] = 1;
			q.push(i);
		}//for()
	}//while()
}//bfs()

int main()
{
	int edge;

	scanf("%d %d", &V, &edge);

	for (int i = 0; i < edge; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		gp[a][b] = 1;
		gp[b][a] = 1;
	}//for()

	bfs(1);
	printf("%d", cnt);
}//main()