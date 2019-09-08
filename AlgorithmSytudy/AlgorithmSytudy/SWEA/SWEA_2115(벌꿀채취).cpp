#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, C;
int board[10][10];
int dp[10][10]; //수익의 최댓값 저장배열

int backTracking(vector<int>honey, int n, int sum, int value)
{
	if (sum > C) return 0;
	if (n == honey.size()) return value;
	return max(backTracking(honey, n + 1, sum + honey[n], value + pow(honey[n], 2)), backTracking(honey, n + 1, sum, value));
}

int getMaxValue(int idx1, int idx2)
{
	vector<int>honey;

	for (int i = 0; i < M; i++)
		honey.push_back(board[idx1][idx2 + i]);

	return backTracking(honey, 0, 0, 0);
}

int dfs(int idx1, int idx2)
{
	int ret = 0;

	//같은 행 
	for (int i = idx2 + M; i < N - M + 1; i++)
		ret = max(ret, dp[idx1][i]);

	//다른 행 
	for (int i = idx1 + 1; i < N; i++)
		for (int j = 0; j < N - M + 1; j++)
			ret = max(ret, dp[i][j]);

	return ret;
}

int main()
{
	int test;
	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		scanf("%d %d %d", &N, &M, &C);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &board[i][j]);


		//배열의 각 위치에서의 수익의 최댓값구하기
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N - M + 1; j++)
				dp[i][j] = getMaxValue(i, j);


		int res = 0;

		//두 일꾼의 최대수익값 구하기
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N - M + 1; j++)
				res = max(res, dp[i][j] + dfs(i, j));


		printf("#%d %d\n", t, res);
	}

	return 0;
}