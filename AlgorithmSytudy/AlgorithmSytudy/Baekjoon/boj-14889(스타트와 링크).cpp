#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int board[21][21];
int visited[21];
int answer = 2e9;

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

void dfs(int idx, int cnt)
{
	if (cnt == N / 2)
	{
		vector<int>start;
		vector<int>link;

		for (int i = 1; i <= N; i++) {
			if (visited[i]) {
				start.push_back(i);
			}
			else {
				link.push_back(i);
			}
		}

		int power_start = 0, power_link = 0;

		for (int i = 0; i < start.size() - 1; i++)
		{
			for (int j = i + 1; j < start.size(); j++)
			{
				power_start += (board[start[i]][start[j]] + board[start[j]][start[i]]);
			}
		}

		for (int i = 0; i < link.size() - 1; i++)
		{
			for (int j = i + 1; j < link.size(); j++)
			{
				power_link += (board[link[i]][link[j]] + board[link[j]][link[i]]);
			}
		}

		answer = min(answer, abs(power_link - power_start));
		return;
	}

	for (int i = idx + 1; i <= N; i++)
	{
		visited[i] = 1;
		dfs(i, cnt + 1);
		visited[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	init();
	dfs(0, 0);
	cout << answer << endl;
	return 0;
}