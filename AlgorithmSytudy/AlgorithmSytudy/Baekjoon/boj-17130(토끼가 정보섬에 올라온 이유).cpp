#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

char board[1001][1001];
int dp[1001][1001];
int r_idx1, r_idx2;
int N, M;
int answer = -1;

void init()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				r_idx1 = i; 
				r_idx2 = j;
			}
		}
	}

	memset(dp, -1, sizeof(dp));
}

void solve()
{
	dp[r_idx1][r_idx2] = 0;

	for (int i = r_idx2, s_up = r_idx1, s_down = r_idx1; i <= M; i++)
	{
		if (s_up - 1 >= 1) s_up--;
		if (s_down + 1 <= N) s_down++;

		for (int j = s_up; j <= s_down; j++)
		{
			if (board[j][i] == '#') continue;
			if (i - 1 >= 1) dp[j][i] = max(dp[j][i], dp[j][i - 1]);
			if (j - 1 >= 1 && i - 1 >= 1) dp[j][i] = max(dp[j][i], dp[j - 1][i - 1]);
			if (j + 1 <= N && i - 1 >= 1) dp[j][i] = max(dp[j][i], dp[j + 1][i - 1]);
			if (board[j][i] == 'C' && dp[j][i] != -1) dp[j][i]++;
			if (board[j][i] == 'O') answer = max(answer, dp[j][i]);
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
	cout << answer << endl;
	return 0;
}