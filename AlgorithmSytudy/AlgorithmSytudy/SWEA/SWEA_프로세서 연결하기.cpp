#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int idx1[] = { 0,0,1,-1 };
const int idx2[] = { 1,-1,0,0 };

int N;
int board[13][13];
vector<Pair>core;
int ans_cnt, ans_sum;

void init()
{
	ans_cnt = 0, ans_sum = 0;
	core.clear();

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &board[i][j]);

			if ((i > 1 && i < N && j>1 && j < N) && board[i][j] == 1)
				core.push_back(Pair(i, j));
		}
	}
}

bool check(Pair start, int way)
{
	Pair next = Pair(start.first + idx1[way], start.second + idx2[way]);

	while (true)
	{
		if (next.first<1 || next.first>N || next.second<1 || next.second>N)
			return true;

		if (board[next.first][next.second] == 1 || board[next.first][next.second] == -1)
			return false;

		next = Pair(next.first + idx1[way], next.second + idx2[way]);
	}
}

void connect(Pair start, int way, int& len)
{
	Pair next = Pair(start.first + idx1[way], start.second + idx2[way]);

	while (true)
	{
		if (next.first<1 || next.first>N || next.second<1 || next.second>N)
			break;

		board[next.first][next.second] = -1;
		len++;
		next = Pair(next.first + idx1[way], next.second + idx2[way]);
	}
}

void unconnect(Pair start, int way, int& len)
{
	Pair next = Pair(start.first + idx1[way], start.second + idx2[way]);

	while (true)
	{
		if (next.first<1 || next.first>N || next.second<1 || next.second>N)
			break;

		board[next.first][next.second] = 0;
		len--;
		next = Pair(next.first + idx1[way], next.second + idx2[way]);
	}
}

void dfs(int idx, int core_cnt, int lenSum)
{
	if (idx >= core.size())
	{
		if (ans_cnt < core_cnt)
		{
			ans_cnt = core_cnt;
			ans_sum = lenSum;
		}
		else if (ans_cnt == core_cnt)
		{
			ans_sum = min(ans_sum, lenSum);
		}
		return;
	}

	bool flag = false;

	for (int i = 0; i < 4; i++)
	{
		if (check(core[idx], i))
		{
			flag = true;
			connect(core[idx], i, lenSum);
			dfs(idx + 1, core_cnt + 1, lenSum);
			unconnect(core[idx], i, lenSum);
		}
	}

	if (!flag)
		dfs(idx + 1, core_cnt, lenSum);
}

int main()
{
	int test;
	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		init();
		dfs(0, 0, 0);
		printf("#%d %d\n", t, ans_sum);
	}

	return 0;
}