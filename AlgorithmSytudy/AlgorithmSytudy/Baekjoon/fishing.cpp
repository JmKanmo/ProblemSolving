#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pos_Pair;

struct Shark
{
	Pos_Pair pos;
	int velocity;
	int size;
	char dir;

	Shark() {}

	Shark& operator = (const Shark& shark)
	{
		this->pos = shark.pos;
		this->velocity = shark.velocity;
		this->size = shark.size;
		this->dir = shark.dir;
		return *this;
	}

	Shark(Pos_Pair pos, int velocity, int size, char dir)
	{
		this->pos = pos;
		this->velocity = velocity;
		this->size = size;
		this->dir = dir;
	}
};

struct Board {
	queue<Shark>q;
};

vector<vector<Board>>board;
queue<Shark>shark_q;
int R, C, M;
int answer;

Pos_Pair getNextPos(Pos_Pair pos, char& dir, int velocity)
{
	if (dir == 'U' && pos.first - 1 == 0) dir = 'D';
	if (dir == 'D' && pos.first + 1 > R) dir = 'U';
	if (dir == 'L' && pos.second - 1 == 0) dir = 'R';
	if (dir == 'R' && pos.second + 1 > C) dir = 'L';

	for (int i = 1; i <= velocity; i++)
	{
		if (dir == 'U')
		{
			pos = Pos_Pair(pos.first - 1, pos.second);
			if (pos.first == 1) dir = 'D';
		}
		else if (dir == 'D')
		{
			pos = Pos_Pair(pos.first + 1, pos.second);
			if (pos.first == R) dir = 'U';
		}
		else if (dir == 'L')
		{
			pos = Pos_Pair(pos.first, pos.second - 1);
			if (pos.second == 1) dir = 'R';
		}
		else
		{
			pos = Pos_Pair(pos.first, pos.second + 1);
			if (pos.second == C) dir = 'L';
		}
	}
	return pos;
}

void move()
{
	while (shark_q.empty() != true)
	{
		Shark shark = shark_q.front();
		shark_q.pop();
		shark.pos = getNextPos(shark.pos, shark.dir, shark.velocity);
		board[shark.pos.first][shark.pos.second].q.push(shark);
	}
}

void merge()
{
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (board[i][j].q.empty() != true)
			{
				int MAX_SIZE = 0;
				Shark shark;

				while (board[i][j].q.empty() != true)
				{
					if (MAX_SIZE < board[i][j].q.front().size)
					{
						MAX_SIZE = board[i][j].q.front().size;
						shark = board[i][j].q.front();
					}
					board[i][j].q.pop();
				}
				board[shark.pos.first][shark.pos.second].q.push(shark);
			}
		}
	}
}

void hunt_Shark(int fisher_pos)
{
	for (int j = 1; j <= R; j++)
	{
		if (board[j][fisher_pos].q.empty() != true)
		{
			answer += board[j][fisher_pos].q.front().size;
			board[j][fisher_pos].q.pop();
			break;
		}
	}
}

void InitVariable() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (board[i][j].q.empty() != true) {
				shark_q.push(board[i][j].q.front());
				board[i][j].q.pop();
			}
		}
	}
}

void solve()
{
	for (int i = 1; i <= C; i++)
	{
		hunt_Shark(i);
		InitVariable();
		move();
		merge();
	}
}

char getIntToCharDir(int dir)
{
	if (dir == 1) return 'U';
	else if (dir == 2) return 'D';
	else if (dir == 3) return 'R';
	else return 'L';
}

int main()
{
	cin >> R >> C >> M;

	board = vector<vector<Board>>(R + 1, vector<Board>(C + 1));

	for (int i = 0; i < M; i++)
	{
		int r, c, s, d, z;
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		board[r][c].q.push(Shark(Pos_Pair(r, c), s, z, getIntToCharDir(d)));
	}
	solve();
	cout << answer << endl;
	return 0;
}
