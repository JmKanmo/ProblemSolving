#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

typedef long long LL;

int N;
char board[6][6];
int visited[6][6];
LL MAX = -2e9, MIN = 2e9;

void init()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> board[i][j];
		}
	}
}

LL calc(LL n1, char op, LL n2)
{
	switch (op)
	{
	case '+': return n1 + n2;
	case '-': return n1 - n2;
	case '*': return n1 * n2;
	}
}

bool check_range(Pair next)
{
	if (next.first<1 || next.first>N || next.second<1 || next.second>N) return false;
	else return true;
}

void dfs(Pair pos, LL val)
{
	if (pos == Pair(N, N))
	{
		MAX = max(val, MAX);
		MIN = min(val, MIN);
		return;
	}

	visited[pos.first][pos.second] = 1;

	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			//right right
			Pair next_1 = Pair(pos.first, pos.second + 1);
			Pair next_2 = Pair(pos.first, pos.second + 2);

			if (check_range(next_1) && check_range(next_2) && !visited[next_2.first][next_2.second])
			{
				dfs(next_2, calc(val, board[next_1.first][next_1.second], board[next_2.first][next_2.second] - '0'));
			}
			//right down
			Pair next_3 = Pair(pos.first, pos.second + 1);
			Pair next_4 = Pair(pos.first + 1, pos.second + 1);

			if (check_range(next_3) && check_range(next_4) && !visited[next_4.first][next_4.second])
			{
				dfs(next_4, calc(val, board[next_3.first][next_3.second], board[next_4.first][next_4.second] - '0'));
			}
		}
		else
		{
			//down down
			Pair next_1 = Pair(pos.first + 1, pos.second);
			Pair next_2 = Pair(pos.first + 2, pos.second);

			if (check_range(next_1) && check_range(next_2) && !visited[next_2.first][next_2.second])
			{
				dfs(next_2, calc(val, board[next_1.first][next_1.second], board[next_2.first][next_2.second] - '0'));
			}
			//right down
			Pair next_3 = Pair(pos.first + 1, pos.second);
			Pair next_4 = Pair(pos.first + 1, pos.second + 1);

			if (check_range(next_3) && check_range(next_4) && !visited[next_4.first][next_4.second])
			{
				dfs(next_4, calc(val, board[next_3.first][next_3.second], board[next_4.first][next_4.second] - '0'));
			}
		}
	}
	visited[pos.first][pos.second] = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	init();
	dfs(Pair(1, 1), board[1][1] - '0');
	cout << MAX << " " << MIN << endl;
	return 0;
}