#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

struct CCTV {
	Pair pos;
	int number;

	CCTV() {}

	CCTV(Pair pos, int number) {
		this->pos = pos;
		this->number = number;
	}
};

const int idx_1[] = { 0,0,1,-1 };
const int idx_2[] = { 1,-1,0,0 };

int N, M;
int answer = 2e9;
vector<vector<int>>board;
vector<CCTV>cctv;

void init()
{
	cin >> N >> M;
	board = vector<vector<int>>(N + 1, vector<int>(M + 1));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] != 0 && board[i][j] != 6) {
				cctv.push_back(CCTV(Pair(i, j), board[i][j]));
			}
		}
	}
}

bool Check_Range(Pair next)
{
	if (next.first<1 || next.first>N || next.second<1 || next.second>M)
		return true;
	else
		return false;
}

void draw_board(vector<vector<int>>& board, Pair pos, int way)
{
	Pair next = pos;

	while (!Check_Range(next) && board[next.first][next.second] != 6)
	{
		if (board[next.first][next.second] <= 0) {
			board[next.first][next.second] = -1;
		}
		next = Pair(next.first + idx_1[way], next.second + idx_2[way]);
	}
}

vector<vector<int>> do_monitor(vector<vector<int>>board, Pair pos, int number, int way)
{
	if (number == 1) {
		switch (way)
		{
		case 1:
			draw_board(board, pos, 0);
			break;
		case 2:
			draw_board(board, pos, 1);
			break;
		case 3:
			draw_board(board, pos, 2);
			break;
		case 4:
			draw_board(board, pos, 3);
			break;
		}
	}
	else if (number == 2) {
		switch (way)
		{
		case 1:case 3:
			draw_board(board, pos, 0);
			draw_board(board, pos, 1);
			break;

		case 2:case 4:
			draw_board(board, pos, 2);
			draw_board(board, pos, 3);
			break;
		}
	}
	else if (number == 3) {
		switch (way)
		{
		case 1:
			draw_board(board, pos, 0);
			draw_board(board, pos, 3);
			break;
		case 2:
			draw_board(board, pos, 0);
			draw_board(board, pos, 2);
			break;
		case 3:
			draw_board(board, pos, 1);
			draw_board(board, pos, 2);
			break;
		case 4:
			draw_board(board, pos, 1);
			draw_board(board, pos, 3);
			break;
		}
	}
	else if (number == 4) {
		switch (way)
		{
		case 1:
			draw_board(board, pos, 0);
			draw_board(board, pos, 1);
			draw_board(board, pos, 3);
			break;
		case 2:
			draw_board(board, pos, 0);
			draw_board(board, pos, 2);
			draw_board(board, pos, 3);
			break;
		case 3:
			draw_board(board, pos, 0);
			draw_board(board, pos, 1);
			draw_board(board, pos, 2);
			break;
		case 4:
			draw_board(board, pos, 2);
			draw_board(board, pos, 3);
			draw_board(board, pos, 1);
			break;
		}
	}
	else if (number == 5) {
		draw_board(board, pos, 0);
		draw_board(board, pos, 1);
		draw_board(board, pos, 2);
		draw_board(board, pos, 3);
	}
	return board;
}

int get_WhiteArea(vector<vector<int>>board) {
	int ret = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (board[i][j] == 0) ret++;
		}
	}
	return ret;
}

void solve(int idx, vector<vector<int>>board)
{
	if (idx >= cctv.size()) {
		answer = min(answer, get_WhiteArea(board));
		return;
	}

	for (int i = 1; i <= 4; i++)
	{
		vector<vector<int>>temp = do_monitor(board, cctv[idx].pos, cctv[idx].number, i);
		solve(idx + 1, temp);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	init();
	solve(0, board);
	cout << answer << endl;
	return 0;
}