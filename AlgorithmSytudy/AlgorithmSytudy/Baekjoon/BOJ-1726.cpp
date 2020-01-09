#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int idx1[] = { 0, 0,0,1,-1 };
const int idx2[] = { 0, 1,-1,0,0 };

struct Pos
{
	Pair pos;
	int dir;
	int cnt = 0;

	Pos() {}

	Pos(Pair pos, int dir, int cnt) {
		this->pos = pos;
		this->dir = dir;
		this->cnt = cnt;
	}
};

int N, M;
int board[101][101];
int visited[101][101][5];
Pos start, goal;

void init()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> board[i][j];
		}
	}

	cin >> start.pos.first >> start.pos.second >> start.dir;
	cin >> goal.pos.first >> goal.pos.second >> goal.dir;
}

void bfs()
{
	queue<Pos>q;
	q.push(start);
	visited[start.pos.first][start.pos.second][start.dir] = 1;

	while (q.empty() != true)
	{
		Pos cur = q.front();
		q.pop();

		if (cur.pos == goal.pos && cur.dir == goal.dir)
		{
			cout << cur.cnt << endl;
			return;
		}

		for (int i = 1; i <= 3; i++)
		{
			Pair next = Pair(cur.pos.first + idx1[cur.dir] * i, cur.pos.second + idx2[cur.dir] * i);
			if (next.first<1 || next.first>N || next.second<1 || next.second>M) break;
			if (board[next.first][next.second]) break;
			if (visited[next.first][next.second][cur.dir]) continue;
			visited[next.first][next.second][cur.dir] = 1;
			q.push(Pos(next, cur.dir, cur.cnt + 1));
		}

		if (cur.dir == 1 || cur.dir == 2)
		{
			Pos next_pos = Pos(cur.pos, 3, cur.cnt + 1);

			if (visited[next_pos.pos.first][next_pos.pos.second][next_pos.dir] == 0)
			{
				q.push(next_pos);
				visited[next_pos.pos.first][next_pos.pos.second][next_pos.dir] = 1;
			}

			next_pos = Pos(cur.pos, 4, cur.cnt + 1);

			if (visited[next_pos.pos.first][next_pos.pos.second][next_pos.dir] == 0)
			{
				q.push(next_pos);
				visited[next_pos.pos.first][next_pos.pos.second][next_pos.dir] = 1;
			}
		}
		else
		{
			Pos next_pos = Pos(cur.pos, 1, cur.cnt + 1);

			if (visited[next_pos.pos.first][next_pos.pos.second][next_pos.dir] == 0)
			{
				q.push(next_pos);
				visited[next_pos.pos.first][next_pos.pos.second][next_pos.dir] = 1;
			}

			next_pos = Pos(cur.pos, 2, cur.cnt + 1);

			if (visited[next_pos.pos.first][next_pos.pos.second][next_pos.dir] == 0)
			{
				q.push(next_pos);
				visited[next_pos.pos.first][next_pos.pos.second][next_pos.dir] = 1;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	init();
	bfs();

	return 0;
}