#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int idx1[] = { 0,0,1,-1 };
const int idx2[] = { 1,-1,0,0 };

int board[9][9];
bool visited[9][9];
vector<Pair> high;
int MAX;
int N, K;
int answer;

void init()
{
	MAX = 0, answer = 0;
	high.clear();

	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &board[i][j]);
			MAX = max(MAX, board[i][j]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (MAX == board[i][j])
				high.push_back(Pair(i, j));
		}
	}
}

void dfs(Pair pos, int depth, bool isCut)
{
	answer = max(answer, depth);

	for (int i = 0; i < 4; i++)
	{
		Pair next = Pair(pos.first + idx1[i], pos.second + idx2[i]);

		if (next.first<1 || next.first>N || next.second<1 || next.second>N) continue;
		if (visited[next.first][next.second]) continue;

		if (board[next.first][next.second] - K >= board[pos.first][pos.second]) continue;

		if (board[pos.first][pos.second] <= board[next.first][next.second])
		{
			if (isCut == false)
			{
				int base_depth = board[next.first][next.second];

				for (int k = 1; k <= K; k++)
				{
					int new_depth = base_depth - k;

					if (board[pos.first][pos.second] > new_depth)
					{
						visited[next.first][next.second] = true;
						board[next.first][next.second] = new_depth;
						dfs(next, depth + 1, true);
						visited[next.first][next.second] = false;
						board[next.first][next.second] = base_depth;
					}
				}
			}
		}
		else
		{
			visited[next.first][next.second] = true;
			dfs(next, depth + 1, isCut);
			visited[next.first][next.second] = false;
		}
	}
}

int main()
{
	int test;
	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		init();

		for (int i = 0; i < high.size(); i++)
		{
			visited[high[i].first][high[i].second] = true;
			dfs(high[i], 1, false);
			visited[high[i].first][high[i].second] = false;
		}

		printf("#%d %d\n", t, answer);
	}

	return 0;
}