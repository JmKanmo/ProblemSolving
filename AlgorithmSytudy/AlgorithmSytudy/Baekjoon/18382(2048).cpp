#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

const int idx_1[] = { 0,0,1,-1 };
const int idx_2[] = { 1,-1,0,0 };

int board[4][4];
bool isMerged[4][4];
int score; //current score
int answer;

int getWayToInt(char way)

{
	switch (way)

	{
	case 'L': return 1;
	case 'R': return 0;
	case 'U': return 3;
	case 'D': return 2;
	}
	return -1;
}

bool checkNext(int nIdx1, int nIdx2)
{
	return nIdx1 < 0 || nIdx1 > 3 || nIdx2 < 0 || nIdx2 > 3 || board[nIdx1][nIdx2] ? true : false;
}

void moveTiles(char way)
{
	int key = getWayToInt(way);

	if (way == 'L')
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int cur_i = i;
				int cur_j = j;
				int temp = board[cur_i][cur_j];
				int ni = cur_i + idx_1[key], nj = cur_j + idx_2[key];

				if (board[cur_i][cur_j] == 0) continue;

				while (!checkNext(ni, nj))
				{
					temp = board[cur_i][cur_j];
					board[cur_i][cur_j] = 0;
					board[ni][nj] = temp;
					cur_i = ni;
					cur_j = nj;
					ni += idx_1[key];
					nj += idx_2[key];
				}

				if (ni < 0 || ni>3 || nj < 0 || nj>3) continue;

				if (board[cur_i][cur_j] == board[ni][nj] && !isMerged[ni][nj]) {
					board[ni][nj] += board[cur_i][cur_j];
					board[cur_i][cur_j] = 0;
					isMerged[ni][nj] = true;
					answer += board[ni][nj];
				}
			}
		}
	}
	else if (way == 'R')
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 3; j >= 0; j--)
			{
				int cur_i = i;
				int cur_j = j;
				int temp = board[cur_i][cur_j];
				int ni = cur_i + idx_1[key], nj = cur_j + idx_2[key];

				if (board[cur_i][cur_j] == 0) continue;

				while (!checkNext(ni, nj))
				{
					temp = board[cur_i][cur_j];
					board[cur_i][cur_j] = 0;
					board[ni][nj] = temp;
					cur_i = ni;
					cur_j = nj;
					ni += idx_1[key];
					nj += idx_2[key];
				}

				if (ni < 0 || ni>3 || nj < 0 || nj>3) continue;

				if (board[cur_i][cur_j] == board[ni][nj] && !isMerged[ni][nj]) {
					board[ni][nj] += board[cur_i][cur_j];
					board[cur_i][cur_j] = 0;
					isMerged[ni][nj] = true;
					answer += board[ni][nj];
				}
			}
		}
	}
	else if (way == 'U')
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int cur_i = i;
				int cur_j = j;
				int temp = board[cur_i][cur_j];
				int ni = cur_i + idx_1[key], nj = cur_j + idx_2[key];

				if (board[cur_i][cur_j] == 0) continue;

				while (!checkNext(ni, nj))
				{
					temp = board[cur_i][cur_j];
					board[cur_i][cur_j] = 0;
					board[ni][nj] = temp;
					cur_i = ni;
					cur_j = nj;
					ni += idx_1[key];
					nj += idx_2[key];
				}

				if (ni < 0 || ni>3 || nj < 0 || nj>3) continue;

				if (board[cur_i][cur_j] == board[ni][nj] && !isMerged[ni][nj]) {
					board[ni][nj] += board[cur_i][cur_j];
					board[cur_i][cur_j] = 0;
					isMerged[ni][nj] = true;
					answer += board[ni][nj];
				}
			}
		}
	}
	else {
		for (int i = 3; i >= 0; i--)
		{
			for (int j = 0; j < 4; j++)
			{
				int cur_i = i;
				int cur_j = j;
				int temp = board[cur_i][cur_j];
				int ni = cur_i + idx_1[key], nj = cur_j + idx_2[key];

				if (board[cur_i][cur_j] == 0) continue;

				while (!checkNext(ni, nj))
				{
					temp = board[cur_i][cur_j];
					board[cur_i][cur_j] = 0;
					board[ni][nj] = temp;
					cur_i = ni;
					cur_j = nj;
					ni += idx_1[key];
					nj += idx_2[key];
				}

				if (ni < 0 || ni>3 || nj < 0 || nj>3) continue;

				if (board[cur_i][cur_j] == board[ni][nj] && !isMerged[ni][nj]) {
					board[ni][nj] += board[cur_i][cur_j];
					board[cur_i][cur_j] = 0;
					isMerged[ni][nj] = true;
					answer += board[ni][nj];
				}
			}
		}
	}
	memset(isMerged, false, sizeof(isMerged));
}

void solve(char way, int idx1, int idx2, int score)
{
	moveTiles(way);
	board[idx1][idx2] += score;
}

void init()
{
	cin >> score;
	string str;
	cin >> str;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> board[i][j];
		}
	}
	for (long long i = 0; i < str.length(); i += 4) {
		solve(str[i], str[i + 2] - '0', str[i + 3] - '0', str[i + 1] - '0');
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	init();
	cout << score + answer << endl;
	return 0;
}