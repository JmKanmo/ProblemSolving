#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

struct Board
{
	int cnt;
	int cheese;
};

const int idx_1[] = { 0,0,1,-1 };
const int idx_2[] = { 1,-1,0,0 };

int N, M;
Board board[101][101];
int visited[101][101];
Pair start;
int cheese_cnt;

void init()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> board[i][j].cheese;
			if (board[i][j].cheese == 1) cheese_cnt++;
			if (board[i][j].cheese == 0 && (i == 1 || i == N || j == 1 || j == M))
				start = Pair(i, j);
		}
	}
}

void bfs()
{
	queue<Pair>q;
	memset(visited, 0, sizeof(visited));

	visited[start.first][start.second] = 1;
	q.push(start);

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Pair next = Pair(pos.first + idx_1[i], pos.second + idx_2[i]);

			if (next.first<1 || next.first>N || next.second<1 || next.second>M)
				continue;

			if (!visited[next.first][next.second] && board[next.first][next.second].cheese == 0)
			{
				visited[next.first][next.second] = 1;
				q.push(next);
			}

			if (board[next.first][next.second].cheese == 1) {
				board[next.first][next.second].cnt++;
			}
		}
	}
}

int getMeltedCheese()
{
	int ret = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (board[i][j].cheese == 1)
			{
				if (board[i][j].cnt >= 2) {
					ret++;
					board[i][j].cnt = 0;
					board[i][j].cheese = 0;
				}
				else {
					board[i][j].cnt = 0;
				}
			}
		}
	}
	return ret;
}

int solve()
{
	int time = 0;
	int melt_cnt = 0;

	while (++time)
	{
		bfs();
		melt_cnt += getMeltedCheese();
		if (melt_cnt == cheese_cnt) break;
	}
	return time;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	init();
	cout << solve() << endl;
	return 0;
}