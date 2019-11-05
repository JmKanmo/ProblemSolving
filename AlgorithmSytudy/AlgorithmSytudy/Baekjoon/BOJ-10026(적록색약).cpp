#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int idx1[] = { 0,0,1,-1 };
const int idx2[] = { 1,-1,0,0 };

char board[101][101];
int N;

vector<vector<int>>visited;

void init()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		string str;
		cin >> str;

		for (int j = 1; j <= N; j++)
			board[i][j] = str[j - 1];
	}

}

void bfs(Pair start, int cnt)
{
	queue<Pair>q;
	char ch = board[start.first][start.second];

	q.push(start);
	visited[start.first][start.second] = cnt;

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Pair next = Pair(pos.first + idx1[i], pos.second + idx2[i]);

			if (next.first<1 || next.first>N || next.second<1 || next.second>N)
				continue;

			if (!visited[next.first][next.second] && board[next.first][next.second] == ch)
			{
				visited[next.first][next.second] = cnt;
				q.push(next);
			}
		}
	}
}

void solve()
{
	int normal_cnt = 0, abnormal_cnt = 0;
	visited = vector<vector<int>>(N + 1, vector<int>(N + 1));

	//Á¤»óÀÎ
	for (int i = 1, cnt = 0; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (!visited[i][j]) {
				bfs(Pair(i, j), ++cnt);
			}
		}
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			normal_cnt = max(normal_cnt, visited[i][j]);

	//ºñÁ¤»óÀÎ
	visited = vector<vector<int>>(N + 1, vector<int>(N + 1));

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			board[i][j] = board[i][j] == 'G' ? 'R' : board[i][j];


	for (int i = 1, cnt = 0; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (!visited[i][j]) {
				bfs(Pair(i, j), ++cnt);
			}
		}
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			abnormal_cnt = max(abnormal_cnt, visited[i][j]);

	cout << normal_cnt << " " << abnormal_cnt << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	init();
	solve();

	return 0;
}