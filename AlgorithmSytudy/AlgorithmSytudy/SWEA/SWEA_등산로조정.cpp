#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int idx1_arr[] = { 0,0,1,-1 };
const int idx2_arr[] = { 1,-1,0,0 };

vector<vector<int>>map(9, vector<int>(9));
vector<vector<bool>>visited(9, vector<bool>(9));

int N, K;
int answer;

void dfs(vector<vector<int>>map, vector<vector<bool>>visited, int idx1,
	int idx2,int cnt, bool isCut)
{
	visited[idx1][idx2] = true;
	answer = max(answer, cnt);

	for (int i = 0; i < 4; i++)
	{
		int n_idx1 = idx1 + idx1_arr[i];
		int n_idx2 = idx2 + idx2_arr[i];

		if (n_idx1<1 || n_idx1>N || n_idx2<1 || n_idx2>N) continue;
		if (visited[n_idx1][n_idx2]) continue;

		if (map[idx1][idx2] <= map[n_idx1][n_idx2])
		{
			if (isCut != true)
			{
				for (int depth = 1; depth <= K; depth++)
				{
					if (map[n_idx1][n_idx2] - depth < map[idx1][idx2])
					{
						int temp = map[n_idx1][n_idx2];
						map[n_idx1][n_idx2] -= depth;
						visited[n_idx1][n_idx2] = true;
						dfs(map, visited, n_idx1, n_idx2, cnt + 1, true);
						visited[n_idx1][n_idx2] = false;
						map[n_idx1][n_idx2] = temp;
					}
				}
			}
		}
		else
		{
			visited[n_idx1][n_idx2] = true;
			dfs(map, visited, n_idx1, n_idx2, cnt + 1, isCut);
			visited[n_idx1][n_idx2] = false;
		}
	}
}

int main()
{
	int test;

	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		scanf("%d %d", &N, &K);

		int high = 0;
		answer = 0;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				scanf("%d", &map[i][j]);
				high = max(high, map[i][j]);
			}
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (map[i][j] == high)
				{
					//dfs함수호출
					dfs(map, visited, i, j, 1, false);
				}
			}
		}
		printf("#%d %d\n", t, answer);
	}
	return 0;
}

