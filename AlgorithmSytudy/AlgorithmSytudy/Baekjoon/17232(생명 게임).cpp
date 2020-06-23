#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, T;
int K, a, b;
char board[101][101][302];
int dp[101][101][302];

void init()
{
	cin >> N >> M >> T;
	cin >> K >> a >> b;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= M; j++) {
			board[i][j][1] = str[j - 1];
		}
	}
}

void setDP(int time)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			dp[i][j][time] = dp[i - 1][j][time] + dp[i][j - 1][time] - dp[i - 1][j - 1][time];
			dp[i][j][time] += (board[i][j][time] == '*' ? 1 : 0);
		}
	}
}

void decideLife(int time)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			pair<int, int> range_w = make_pair(j - K - 1 < 0 ? 0 : j - K - 1, j + K > M ? M : j + K);
			pair<int, int> range_h = make_pair(i - K - 1 < 0 ? 0 : i - K - 1, i + K > N ? N : i + K);

			int cnt = dp[range_h.second][range_w.second][time]
				- dp[range_h.first][range_w.second][time]
				- dp[range_h.second][range_w.first][time] + dp[range_h.first][range_w.first][time];

			cnt += (board[i][j][time] == '*' ? -1 : 0);

			if (board[i][j][time] == '*')
			{
				if (cnt >= a && cnt <= b)
				{
					board[i][j][time + 1] = '*';
				}
				else
				{
					board[i][j][time + 1] = '.';
				}
			}
			else
			{
				if (cnt > a && cnt <= b)
				{
					board[i][j][time + 1] = '*';
				}
				else
				{
					board[i][j][time + 1] = '.';
				}
			}
		}
	}
}

void answer(int time)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cout << board[i][j][time];
		}
		cout << "\n";
	}
}

void solve()
{
	int time = 0;

	while (++time <= T)
	{
		setDP(time);
		decideLife(time);
		memset(dp, 0, sizeof(dp));
	}
	answer(time);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	init();
	solve();
	return 0;
}