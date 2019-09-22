#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, H;
int board[31][11];
int answer = 2e9;

void init()
{
	scanf("%d %d %d", &N, &M, &H);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		board[a][b] = 1;
	}
}

bool check()
{
	for (int i = 1; i <= N; i++)
	{
		int start = i, end = i;

		for (int j = 1; j <= H; j++)
		{
			if (board[j][end - 1]==1) end -= 1;
			else if (board[j][end]==1) end += 1;
		}
		if (start != end) return false;
	}
	return true;
}

void dfs(int idx1, int idx2, int cnt)
{
	if (cnt >= answer) return;

	if (check())
	{
		answer = min(answer, cnt);
		return;
	}

	if (cnt >= 3) return;

	for (int i = idx1; i <= H; i++)
	{
		for (int j = idx2; j < N; j++)
		{
			if (board[i][j - 1] || board[i][j] || board[i][j + 1]) continue;
			board[i][j] = 1;
			dfs(i, j + 2, cnt + 1);
			board[i][j] = 0;
		}
		idx2 = 1;
	}
}

int main()
{
	init();
	dfs(1, 1, 0);
	if (answer > 3)printf("-1\n");
	else printf("%d\n", answer);
	return 0;
}