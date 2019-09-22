#include <iostream>
#include <vector>
#include <algorithm>

#define DEPTH 1

using namespace std;

typedef pair<int, int> Pair;

int N, X;
int board[21][21];
int visited[21][21];

void init()
{
	scanf("%d %d", &N, &X);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}
}

bool check_horizontal(Pair pos1, Pair pos2)
{
	if (abs(board[pos1.first][pos1.second] - board[pos2.first][pos2.second]) == 0) return true;
	if (abs(board[pos1.first][pos1.second] - board[pos2.first][pos2.second]) > DEPTH) return false;

	if (board[pos1.first][pos1.second] > board[pos2.first][pos2.second])
	{
		// 방향: Right
		if (N - pos1.second < X)
			return false;

		int val = board[pos2.first][pos2.second];
		Pair start = pos2;

		for (int i = 0; i < X; i++)
		{
			if (val != board[start.first][start.second]) return false;
			if (visited[start.first][start.second]) return false;
			visited[start.first][start.second] = 1;
			start = Pair(start.first, start.second + 1);
		}
	}
	else
	{
		// 방향: Left
		if (pos2.second - 1 < X)
			return false;

		int val = board[pos1.first][pos1.second];
		Pair start = pos1;

		for (int i = 0; i < X; i++)
		{
			if (val != board[start.first][start.second]) return false;
			if (visited[start.first][start.second]) return false;
			visited[start.first][start.second] = 1;
			start = Pair(start.first, start.second - 1);
		}
	}
	return true;
}

bool check_vertical(Pair pos1, Pair pos2)
{
	if (abs(board[pos1.first][pos1.second] - board[pos2.first][pos2.second]) == 0) return true;
	if (abs(board[pos1.first][pos1.second] - board[pos2.first][pos2.second]) > DEPTH) return false;

	if (board[pos1.first][pos1.second] > board[pos2.first][pos2.second])
	{
		// 방향: Down
		if (N - pos1.first < X)
			return false;

		int val = board[pos2.first][pos2.second];
		Pair start = pos2;

		for (int i = 0; i < X; i++)
		{
			if (val != board[start.first][start.second]) return false;
			if (visited[start.first][start.second]) return false;
			visited[start.first][start.second] = 1;
			start = Pair(start.first + 1, start.second);
		}
	}
	else
	{
		// 방향: Up
		if (pos2.first - 1 < X)
			return false;

		int val = board[pos1.first][pos1.second];
		Pair start = pos1;

		for (int i = 0; i < X; i++)
		{
			if (val != board[start.first][start.second]) return false;
			if (visited[start.first][start.second]) return false;
			visited[start.first][start.second] = 1;
			start = Pair(start.first - 1, start.second);
		}
	}

	return true;
}

int solve()
{
	int cnt = 0;

	//1단계
	for (int i = 1; i <= N; i++)
	{
		bool flag = true;

		for (int j = 1; j < N; j++)
		{
			if (check_horizontal(Pair(i, j), Pair(i, j + 1)) != true)
			{
				flag = false;
				break;
			}
		}
		cnt = flag ? cnt + 1 : cnt;
	}

	fill(&visited[0][0], &visited[0][0] + 21 * 21, 0);

	//2단계
	for (int i = 1; i <= N; i++)
	{
		bool flag = true;

		for (int j = 1; j < N; j++)
		{
			if (check_vertical(Pair(j, i), Pair(j + 1, i)) != true)
			{
				flag = false;
				break;
			}
		}
		cnt = flag ? cnt + 1 : cnt;
	}
	fill(&visited[0][0], &visited[0][0] + 21 * 21, 0);
	return cnt;
}

int main()
{
	int test;
	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		init();
		int cnt = solve();
		printf("#%d %d\n", t, cnt);
	}

	return 0;
}