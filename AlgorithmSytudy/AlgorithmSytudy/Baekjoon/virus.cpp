#include "pch.h"
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

queue<int>q;//bfs�� ���� ť
int gp[101][101]; //�������(�׷���) ǥ��
int visit[101]; //�湮��������迭
int cnt;
int V;

//���̿켱Ž��(DFS) �Լ�
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


//�ʺ�켱Ž��(bfs) �Լ�
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