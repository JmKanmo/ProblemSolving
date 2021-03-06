#include "pch.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

/*
2018.10.23
BFS 실습(백준 2178)
두부
*/

typedef pair<int, int> Pair; //(2개의 int값을 저장하는 자료구조)

#define MAX 101

enum {
	UP = 1,
	DOWN = 2,
	LEFT = 3,
	RIGHT = 4
};

int maze[MAX][MAX]; // 미로를 표현하는 2차원배열
int cost[MAX][MAX];  //지나야할 칸의 수를 담은 2차원배열
int visit[MAX][MAX]; //방문여부를 저장하는 2차원배열


//너비우선탐색(bfs)을 수행하는 함수

void bfs(int n, int m)
{   
	queue<Pair>q; //bfs를 수행하기 위한 큐 선언

	cost[1][1] = 1;
	visit[1][1] = 1;
	q.push(Pair(1, 1));

	//bfs수행
	while (q.empty() != true)
	{
		Pair pair = q.front();
		q.pop();
		
		//4방향(동서남북)탐색수행 
		for (int i = 1; i <= 4; i++)
		{
			int pos1 = pair.first;
			int pos2 = pair.second;

			switch (i)
			{
			case UP:
				pos1 -= 1;
				break;
			case DOWN:
				pos1 += 1;
				break;
			case LEFT:
				pos2 -= 1;
				break;
			case RIGHT:
				pos2 += 1;
				break;
			}//switch()

			if ((pos1<1 && pos1>n) || (pos2<1 && pos2>m))
				continue;

			if (maze[pos1][pos2] == 0)
				continue;

			if (visit[pos1][pos2] != 0)
				continue;

			cost[pos1][pos2] = cost[pair.first][pair.second] + 1;
			visit[pos1][pos2] = 1;

			if (pos1 == n && pos2 == m)
				return;

			q.push(Pair(pos1, pos2));
		}//for()
	}//while()
}//bfs()

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		char*input = new char[m + 1]; //동적배열할당 & 입력값저장
		scanf("%s", input);

		for (int j = 1; j <= m; j++)
			maze[i][j] = input[j - 1] - 48;
		
		delete[]input; //할당받은배열 소멸
	}//for()

	//bfs함수호출
	bfs(n, m);

	//결과값 출력
	printf("%d", cost[n][m]);
	return 0;
}//main()