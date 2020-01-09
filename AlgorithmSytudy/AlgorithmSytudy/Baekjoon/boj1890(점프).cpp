#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int N;
int board[101][101];
LL dp[101][101];

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

void solve()
{
	dp[1][1] = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (board[i][j] == 0) return;

			int h_next = i + board[i][j];

			if (h_next <= N)
				dp[h_next][j] += dp[i][j];
			
			int w_next = j + board[i][j];

			if (w_next <= N)
				dp[i][w_next] += dp[i][j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	init();
	solve();
	cout << dp[N][N] << endl;
	return 0;
}