#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

vector<int>dice(7);
int board[25][25];

int n, m;
Pair dice_pos;
vector<int>order;

vector<int> dice_move(vector<int>dice, int dir)
{
	vector<int>temp = dice;

	if (dir == 1)

	{
		//오른쪽이동
		dice[3] = temp[6];
		dice[6] = temp[2];
		dice[2] = temp[1];
		dice[1] = temp[3];
	}
	else if (dir == 2)
	{
		//왼쪽이동
		dice[6] = temp[3];
		dice[3] = temp[1];
		dice[1] = temp[2];
		dice[2] = temp[6];
	}
	else if (dir == 3)
	{
		//위쪽이동
		dice[4] = temp[1];
		dice[1] = temp[5];
		dice[5] = temp[6];
		dice[6] = temp[4];
	}
	else
	{
		//아래쪽이동
		dice[4] = temp[6];
		dice[6] = temp[5];
		dice[5] = temp[1];
		dice[1] = temp[4];
	}
	return dice;
}

Pair getNextPos(Pair dice_pos, int dir)
{
	switch (dir)
	{
	case 1: return Pair(dice_pos.first, dice_pos.second + 1);
	case 2: return Pair(dice_pos.first, dice_pos.second - 1);
	case 3: return Pair(dice_pos.first - 1, dice_pos.second);
	case 4: return Pair(dice_pos.first + 1, dice_pos.second);
	}
}

bool isOutofRange(Pair dice_pos, int dir) {
	Pair next = getNextPos(dice_pos, dir);
	if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m) return true;
	else return false;
}

void diceRolling()
{
	for (int i = 0; i < order.size(); i++)
	{
		if (i == 1)
		{
			//오른쪽이동
			if (isOutofRange(dice_pos, order[i])) continue;
			else {
				dice = dice_move(dice, order[i]);
				dice_pos = getNextPos(dice_pos,order[i]);	
			}
		}
		else if (i == 2)
		{
			//왼쪽이동
			if (isOutofRange(dice_pos, order[i])) continue;
			else {
				dice = dice_move(dice, order[i]);
				dice_pos = getNextPos(dice_pos, order[i]);
			}
		}
		else if (i == 3)
		{
			//위쪽이동
			if (isOutofRange(dice_pos, order[i])) continue;
			else {
				dice = dice_move(dice, order[i]);
				dice_pos = getNextPos(dice_pos, order[i]);
			}
		}
		else
		{
			//아래쪽이동
			if (isOutofRange(dice_pos, order[i])) continue;
			else {
				dice = dice_move(dice, order[i]);
				dice_pos = getNextPos(dice_pos, order[i]);
			}
		}
		if (board[dice_pos.first][dice_pos.second] == 0) {
			board[dice_pos.first][dice_pos.second] = dice[6];
		}
		else {
			dice[6] = board[dice_pos.first][dice_pos.second];
			board[dice_pos.first][dice_pos.second] = 0;
		}
		printf("%d\n", dice[1]);
	}
}

int main()
{
	int x, y, k;

	cin >> n >> m >> x >> y >> k;
	dice_pos = Pair(x, y);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	for (int i = 0; i < k; i++) {
		int dir;
		scanf("%d", &dir);
		order.push_back(dir);
	}

	diceRolling();
	return 0;
}