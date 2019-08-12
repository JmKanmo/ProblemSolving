#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pos_Pair;

const int idx1[] = { 0,0,1,-1 };
const int idx2[] = { 1,-1,0,0 };

struct Tunnel {
	int type = 0;
	bool left = false;
	bool right = false;
	bool up = false;
	bool down = false;

	Tunnel() {}

	void setDirection()
	{
		if (type == 1)
		{
			left = true;
			right = true;
			up = true;
			down = true;
		}
		else if (type == 2)
		{
			up = true;
			down = true;
		}
		else if (type == 3)
		{
			left = true;
			right = true;
		}
		else if (type == 4)
		{
			up = true;
			right = true;
		}
		else if (type == 5)
		{
			down = true;
			right = true;
		}
		else if (type == 6)
		{
			down = true;
			left = true;
		}
		else if (type == 7)
		{
			up = true;
			left = true;
		}
	}
};

vector<vector<Tunnel>>board;
vector<vector<bool>>visited;
vector<vector<int>>step;

int N, M, L;
Pos_Pair start;

void bfs()
{
	queue<Pos_Pair> q;
	visited[start.first][start.second] = true;
	step[start.first][start.second] = 1;
	q.push(start);

	while (q.empty() != true)
	{
		Pos_Pair pos = q.front();
		q.pop();

		if (step[pos.first][pos.second] == L) {
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			Pos_Pair next_pos = Pos_Pair(pos.first + idx1[i], pos.second + idx2[i]);

			if (next_pos.first < 0 || next_pos.first >= N || next_pos.second < 0 || next_pos.second >= M) continue;

			if (board[next_pos.first][next_pos.second].type == 0 || visited[next_pos.first][next_pos.second]) continue;

			if (i == 0)
			{
				//동
				if (!board[pos.first][pos.second].right || !board[next_pos.first][next_pos.second].left)
					continue;
			}
			else if (i == 1)
			{
				//서
				if (!board[pos.first][pos.second].left || !board[next_pos.first][next_pos.second].right)
					continue;
			}
			else if (i == 2)
			{
				//남
				if (!board[pos.first][pos.second].down || !board[next_pos.first][next_pos.second].up)
					continue;
			}
			else
			{
				//북
				if (!board[pos.first][pos.second].up || !board[next_pos.first][next_pos.second].down)
					continue;
			}
			visited[next_pos.first][next_pos.second] = true;
			step[next_pos.first][next_pos.second] = step[pos.first][pos.second] + 1;
			q.push(next_pos);
		}
	}
}

int getCntOfPos()
{
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cnt = visited[i][j] ? cnt + 1 : cnt;
		}
	}
	return cnt;
}

int main()
{
	int test;
	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		scanf("%d %d %d %d %d", &N, &M, &start.first, &start.second, &L);

		board = vector<vector<Tunnel>>(N, vector<Tunnel>(M));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%d", &board[i][j].type);
				board[i][j].setDirection();
			}
		}
		visited = vector<vector<bool>>(50, vector<bool>(50));
		step = vector<vector<int>>(50, vector<int>(50));
		//bfs함수호출
		bfs();
		printf("#%d %d\n", t, getCntOfPos());
	}
	return 0;
}