#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

typedef pair<int, int>Pair;

const int idx1[] = { 0,0,1,-1 };
const int idx2[] = { 1,-1,0,0 };

int board[21][21];
vector<vector<bool>>visited = vector<vector<bool>>(21, vector<bool>(21));
int N, M;
int answer;

void init()
{
	answer = 0;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &board[i][j]);
}

void bfs(Pair start, vector<vector<bool>>visited)
{
	queue<Pair>q;
	int K = 1;
	int home = board[start.first][start.second] == 1 ? 1 : 0;

	q.push(start);
	visited[start.first][start.second] = true;

	while (q.empty() != true)
	{
		if (home * M - (K * K + (K - 1) * (K - 1)) >= 0) {
			answer = max(answer, home);
		}

		int q_size = q.size();

		while (q_size--)
		{
			Pair pos = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				Pair next = Pair(pos.first + idx1[i], pos.second + idx2[i]);

				if (next.first<1 || next.first>N || next.second<1 || next.second>N) continue;

				if (visited[next.first][next.second] != true)
				{
					if (board[next.first][next.second] == 1) {
						home++;
					}
					visited[next.first][next.second] = true;
					q.push(next);
				}
			}
		}
		K++;
	}
}

int main()
{
	int test;
	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		init();
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				bfs(Pair(i, j), visited);
			}
		}
		printf("#%d %d\n", t, answer);
	}

	return 0;
}