#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> Pair;

const int idx1[] = { 0,0,1,-1 };
const int idx2[] = { 1,-1,0,0 };

vector<vector<int>>board(51, vector<int>(51));
vector<vector<int>>temp_board;
vector<Pair>cleaner;

int r, c, t;

void sprayDust()
{
	temp_board = board;

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1, cnt = 0; j <= c; j++)
		{
			if (board[i][j] == -1 || board[i][j] == 0) continue;

			for (int k = 0; k < 4; k++) {
				Pair next = Pair(i + idx1[k], j + idx2[k]);
				if (next.first<1 || next.first>r || next.second<1 || next.second>c || board[next.first][next.second] == -1) continue;
				board[next.first][next.second] += temp_board[i][j] / 5;
				cnt++;
			}
			board[i][j] -= ((temp_board[i][j] / 5) * cnt);
			cnt = 0;
		}
	}
}

void windblow()
{
	Pair cleaner_1 = cleaner[0]; // up
	Pair cleaner_2 = cleaner[1]; // bottom

	//1
	int idx1 = cleaner_1.first, idx2 = cleaner_1.second;

	for (int t = 0; t < 4; t++)
	{
		if (t == 0)
		{
			for (int i = idx1 - 1; i >= 1; i--) {
				if (board[i][idx2] != 0) {
					if (board[i + 1][idx2] == -1) {
						board[i][idx2] = 0;
					}
					else {
						board[i + 1][idx2] = board[i][idx2];
						board[i][idx2] = 0;
					}
				}
			}
		}
		else if (t == 1)
		{
			for (int i = 2; i <= c; i++) {
				if (board[1][i] != 0) {
					board[1][i - 1] = board[1][i];
					board[1][i] = 0;
				}
			}
		}
		else if (t == 2)
		{
			for (int i = 2; i <= idx1; i++) {
				if (board[i][c] != 0) {
					board[i - 1][c] = board[i][c];
					board[i][c] = 0;
				}
			}
		}
		else
		{
			for (int i = c - 1; i >= 2; i--) {
				if (board[idx1][i] != 0) {
					board[idx1][i + 1] = board[idx1][i];
					board[idx1][i] = 0;
				}
			}
		}
	}

	//2
	idx1 = cleaner_2.first, idx2 = cleaner_2.second;

	for (int t = 0; t < 4; t++)
	{
		if (t == 0)
		{
			for (int i = idx1 + 1; i <= r; i++) {
				if (board[i][idx2] != 0) {
					if (board[i - 1][idx2] == -1) {
						board[i][idx2] = 0;
					}
					else {
						board[i - 1][idx2] = board[i][idx2];
						board[i][idx2] = 0;
					}
				}
			}
		}
		else if (t == 1)
		{
			for (int i = idx2 + 1; i <= c; i++) {
				if (board[r][i] != 0) {
					board[r][i - 1] = board[r][i];
					board[r][i] = 0;
				}
			}
		}
		else if (t == 2)
		{
			for (int i = r-1; i >=idx1; i--) {
				if (board[i][c] != 0) {
					board[i + 1][c] = board[i][c];
					board[i][c] = 0;
				}
			}
		}
		else
		{
			for (int i = c - 1; i >= idx2 + 1; i--) {
				if (board[idx1][i] != 0) {
					board[idx1][i + 1] = board[idx1][i];
					board[idx1][i] = 0;
				}
			}
		}
	}
}

void cleanDust()
{
	for (int i = 0; i < t; i++)
	{
		sprayDust();
		windblow();
	}
}

int getSumOfDust()
{
	int answer = 0;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (board[i][j] != -1) answer += board[i][j];
		}
	}
	return answer;
}

int main()
{
	cin >> r >> c >> t;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == -1) cleaner.push_back(Pair(i, j));
		}
	}

	cleanDust();
	cout << getSumOfDust() << endl;
	return 0;
}