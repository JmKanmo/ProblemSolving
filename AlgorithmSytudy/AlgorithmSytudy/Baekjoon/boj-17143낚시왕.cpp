#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int, int> Pair;

struct Shark
{
	int size;
	int velocity;
	char way;
	bool moved = false;

	Shark() {}

	Shark(int size, int velocity, char way)
	{
		this->size = size;
		this->velocity = velocity;
		this->way = way;
	}
};

struct Board
{
	queue<Shark>q;
};

int R, C, M;
Board board[101][101];

pair<Pair, char> shark_move(int v, char way, Pair pos)
{
	while (v != 0)
	{
		if (way == 'U') {
			int diff = (pos.first - 1) * 2;

			if (v >= diff) {
				v -= diff;
				way = 'D';
			}
			else {
				if (v <= (diff / 2))
				{
					pos.first -= v;
				}
				else
				{
					pos.first = 1 + (v - (diff / 2));
					way = 'D';
				}
				v = 0;
			}
		}
		else if (way == 'D') {
			int diff = (R - pos.first) * 2;

			if (v >= diff) {
				v -= diff;
				way = 'U';
			}
			else {
				if (v <= (diff / 2))
				{
					pos.first += v;
				}
				else
				{
					pos.first = R - (v - (diff / 2));
					way = 'U';
				}
				v = 0;
			}
		}
		else if (way == 'L') {
			int diff = (pos.second - 1) * 2;

			if (v >= diff) {
				v -= diff;
				way = 'R';
			}
			else {
				if (v <= (diff / 2))
				{
					pos.second -= v;
				}
				else
				{
					pos.second = 1 + (v - (diff / 2));
					way = 'R';
				}
				v = 0;
			}
		}
		else if (way == 'R') {
			int diff = (C - pos.second) * 2;

			if (v >= diff) {
				v -= diff;
				way = 'L';
			}
			else {
				if (v <= (diff / 2))
				{
					pos.second += v;
				}
				else
				{
					pos.second = C - (v - (diff / 2));
					way = 'L';
				}
				v = 0;
			}
		}
	}
	return make_pair(pos, way);
}

void move_func()
{
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (board[i][j].q.empty() != true)
			{
				Shark shark = board[i][j].q.front();

				if (shark.moved == false)
				{
					board[i][j].q.pop();
					pair<Pair, char>moved = shark_move(shark.velocity, shark.way, Pair(i, j));
					shark.moved = true;
					shark.way = moved.second;
					board[moved.first.first][moved.first.second].q.push(shark);
				}
			}
		}
	}
}

void eat_func()
{
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (board[i][j].q.empty() != true)
			{
				Shark max_shark;
				int MAX_SIZE = 0;

				while (board[i][j].q.empty() != true)
				{
					Shark shark = board[i][j].q.front();
					if (MAX_SIZE < shark.size) {
						MAX_SIZE = shark.size;
						max_shark = shark;
					}
					board[i][j].q.pop();
				}
				max_shark.moved = false;
				board[i][j].q.push(max_shark);
			}
		}
	}
}

int solve()
{
	int size = 0;

	for (int i = 1; i <= C; i++)
	{
		for (int j = 1; j <= R; j++)
		{
			if (board[j][i].q.empty() != true)
			{
				Shark shark = board[j][i].q.front();
				board[j][i].q.pop();
				size += shark.size;
				break;
			}
		}
		move_func();
		eat_func();
	}
	return size;
}

char getWay(int way)
{
	switch (way)
	{
	case 1:
		return 'U';
	case 2:
		return 'D';
	case 3:
		return 'R';
	case 4:
		return 'L';
	}
}

void init()
{
	cin >> R >> C >> M;

	for (int i = 1; i <= M; i++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		board[r][c].q.push(Shark(z, s, getWay(d)));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	init();
	cout << solve() << endl;
	return 0;
}