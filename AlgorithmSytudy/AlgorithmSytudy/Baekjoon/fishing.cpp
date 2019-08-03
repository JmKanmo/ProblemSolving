#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int idx1[] = { 0,-1,1,0,0 };
const int idx2[] = { 0,0,0,1,-1 };

struct shark {
	int speed;
	int direction;
	int size;
	bool ismove = false;

	shark() {}
	shark(int speed, int direction, int size) :speed(speed), direction(direction), size(size) {}
};

typedef pair<int, int> Pos_Pair;
typedef pair<int, queue<shark>>Board_Pair;

Board_Pair board[101][101];

int n, m, shark_cnt;
int hunting_sum;

int getReverseDirection(int direction) {
	switch (direction) {
	case 1: return 2;
	case 2: return 1;
	case 3:	return 4;
	case 4:	return 3;
	}
}

Pos_Pair getSharkMovedPos(Pos_Pair shark_pos,int& direction, int speed)
{
	for (int i = 1; i <= speed; i++) {
		Pos_Pair next = Pos_Pair(shark_pos.first + idx1[direction], shark_pos.second + idx2[direction]);
		if (next.first<1 || next.first>n || next.second<1 || next.second>m) {
			direction = getReverseDirection(direction);
			next = Pos_Pair(shark_pos.first + idx1[direction], shark_pos.second + idx2[direction]);
		}
		shark_pos = next;
	}
	return shark_pos;
}

void shark_moving()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (board[i][j].first != 0 && board[i][j].second.front().ismove != true)
			{
				Pos_Pair moved_pos = getSharkMovedPos(Pos_Pair(i, j), board[i][j].second.front().direction, board[i][j].second.front().speed);
				board[i][j].second.front().ismove = true;
				board[moved_pos.first][moved_pos.second].second.push(board[i][j].second.front());
				board[i][j].second.pop();
				if (board[i][j].second.empty() == true) board[i][j].first = 0;
				board[moved_pos.first][moved_pos.second].first = 1;
			}
		}
	}
}

void shark_fight()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (board[i][j].second.size() > 1)
			{
				shark max_shark = shark(0, 0, -999);

				while (board[i][j].second.empty() != true)
				{
					shark pop_shark = board[i][j].second.front();
					max_shark = pop_shark.size > max_shark.size ? pop_shark : max_shark;
					board[i][j].second.pop();
				}
				board[i][j].second.push(max_shark);
			}
			if (board[i][j].second.size() > 0) board[i][j].second.front().ismove = false;
		}
	}
}

void fishing_shark()
{
	for (int i = 1, fisher = 0; i <= m; i++)
	{
		fisher += 1;

		for (int j = 1; j <= n; j++) {
			if (board[j][fisher].first == 1) {
				hunting_sum += board[j][fisher].second.front().size;
				board[j][fisher].first = 0;
				board[j][fisher].second.pop();
				break;
			}
		}
		shark_moving();
		shark_fight();
	}
}

int main()
{
	cin >> n >> m >> shark_cnt;

	for (int i = 1; i <= shark_cnt; i++)
	{
		int r, c, s, d, z;
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		board[r][c].first = 1;
		board[r][c].second.push(shark(s, d, z));
	}

	fishing_shark();
	cout << hunting_sum << endl;
	return 0;
}