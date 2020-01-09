#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int idx_1[] = { 0,0,1,-1 };
const int idx_2[] = { 1,-1,0,0 };

int W, H;
char board[101][101];
int step[101][101];
Pair start, goal;

void init()
{
	cin >> W >> H;

	for (int i = 1, cnt = 1; i <= H; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= W; j++)
		{
			board[i][j] = str[j - 1];
			step[i][j] = -1;
			if (board[i][j] == 'C' && cnt++ == 1) start = Pair(i, j);
			else if (board[i][j] == 'C' && cnt != 1) goal = Pair(i, j);
		}
	}
}

void bfs()
{
	queue<Pair>q;
	q.push(start);
	step[start.first][start.second] = 0;

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();

		if (pos == goal) break;

		for (int i = 0; i < 4; i++)
		{
			Pair next = pos;

			while (true)
			{
				next = Pair(next.first + idx_1[i], next.second + idx_2[i]);
				if ((next.first < 1 || next.first > H || next.second<1 || next.second > W) || board[next.first][next.second] == '*') break;
				if (step[next.first][next.second] != -1) continue;
				step[next.first][next.second] = step[pos.first][pos.second] + 1;
				q.push(next);
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
	cout << step[goal.first][goal.second] - 1 << endl;
	return 0;
}