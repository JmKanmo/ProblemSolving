#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

struct Bio
{
	Pair pos;
	int number;
	char dir;

	Bio() {}

	Bio(Pair pos, int number, char dir) {
		this->pos = pos;
		this->number = number;
		this->dir = dir;
	}
};

struct Board {
	queue<Bio>q;
};

int N, M, K;

vector<Bio>bio_vector;
vector<vector<Board>>board;

Pair getNextPos(Pair pos, char dir)
{
	switch (dir)
	{
	case 'U': return Pair(pos.first - 1, pos.second);
	case 'D': return Pair(pos.first + 1, pos.second);
	case 'L': return Pair(pos.first, pos.second - 1);
	case 'R': return Pair(pos.first, pos.second + 1);
	}
}

char getReversedDir(char dir)
{
	switch (dir)
	{
	case 'U': return 'D';
	case 'D': return 'U';
	case 'L': return 'R';
	case 'R': return 'L';
	}
}

void move()
{
	for (int i = 0; i < bio_vector.size(); i++)
	{
		Bio bio = bio_vector[i];
		bio.pos = getNextPos(bio.pos, bio.dir);

		if (bio.pos.first == 0 || bio.pos.first == N - 1 || bio.pos.second == 0 || bio.pos.second == N - 1) {
			bio.number /= 2;
			bio.dir = getReversedDir(bio.dir);
			if (bio.number == 0) continue;
		}
		board[bio.pos.first][bio.pos.second].q.push(Bio(bio.pos, bio.number, bio.dir));
	}
	bio_vector.clear();
}

void merge()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j].q.empty() != true)
			{
				int sum = 0;
				int MAX = 0;
				char dir = 0;

				while (board[i][j].q.empty() != true)
				{
					if (MAX < board[i][j].q.front().number) {
						MAX = board[i][j].q.front().number;
						dir = board[i][j].q.front().dir;
					}
					sum += board[i][j].q.front().number;
					board[i][j].q.pop();
				}
				bio_vector.push_back(Bio(Pair(i, j), sum, dir));
			}
		}
	}
}

void solve()
{
	int time = 0;

	while (time < M)
	{
		move();
		merge();
		time++;
	}
}

int getCntOfBio() {
	int cnt = 0;
	for (int i = 0; i < bio_vector.size(); i++) {
		cnt += bio_vector[i].number;
	}
	bio_vector.clear();
	return cnt;
}

char getNumberToDir(int dir) {
	if (dir == 1) return 'U';
	else if (dir == 2) return  'D';
	else if (dir == 3) return  'L';
	else return 'R';
}

int main()
{
	int test;
	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		scanf("%d %d %d", &N, &M, &K);

		board = vector<vector<Board>>(101, vector<Board>(101));

		for (int i = 0; i < K; i++)
		{
			int a, b, c, d;
			scanf("%d %d %d %d", &a, &b, &c, &d);
			bio_vector.push_back(Bio(Pair(a, b), c, getNumberToDir(d)));
		}
		solve();
		printf("#%d %d\n", t, getCntOfBio());
	}

	return 0;
}