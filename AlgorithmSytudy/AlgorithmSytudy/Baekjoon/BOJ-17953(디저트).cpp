#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int N, M;
int board[11][100001];
int dp[11][100001];

void init()
{
	cin >> N >> M;

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> board[i][j];
			if (j == 1) dp[i][j] = board[i][j];
		}
	}
}

int solve()
{
	//로직작성
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			for (int k = 1; k <= M; k++)
			{
				if (j == k)
				{
					//절반감소
					dp[j][i] = max(dp[j][i], dp[k][i - 1] + board[j][i] / 2);
				}
				else
				{
					//그대로
					dp[j][i] = max(dp[j][i], dp[k][i - 1] + board[j][i]);
				}
			}
		}
	}

	int MAX = 0;	
	for (int i = 1; i <= M; i++) MAX = max(MAX, dp[i][N]);

	return MAX;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	init();
	cout << solve() << endl;
	return 0;
}