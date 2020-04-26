#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int idx_1[] = { 0,0,1,-1 };
const int idx_2[] = { 1,-1,0,0 };

int N, K;
int board[101][11];
vector<vector<int>>visited(101, vector<int>(11));

void init()
{
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		string str;
		cin >> str;

		for (int j = 1; j <= 10; j++)
			board[i][j] = (str[j - 1] - '0');
	}
}

void fallDown()
{
	for (int i = N; i >= 1; i--)
	{
		for (int j = 1; j <= 10; j++)
		{
			if (board[i][j] != 0)
			{
				Pair pos = Pair(i, j);
				Pair next = pos;
				while (next.first < N && !board[next.first + 1][next.second]) next.first++;
				int temp_n = board[pos.first][pos.second];
				board[pos.first][pos.second] = 0;
				board[next.first][next.second] = temp_n;
			}
		}
	}
}

bool bfs(Pair start)
{
	queue<Pair>q;
	vector<vector<int>>temp_visited = visited;
	int cnt = 0;

	q.push(start);
	temp_visited[start.first][start.second] = 1;

	while (q.empty() != true)
	{
		Pair pos = q.front();
		cnt++;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Pair next = Pair(pos.first + idx_1[i], pos.second + idx_2[i]);

			if (next.first<1 || next.first>N || next.second < 1 || next.second>10
				|| temp_visited[next.first][next.second]) continue;

			if (board[pos.first][pos.second] == board[next.first][next.second])
			{
				temp_visited[next.first][next.second] = 1;
				q.push(next);
			}
		}
	}
	if (cnt >= K) {
		visited = temp_visited;
		return true;
	}
	else {
		return false;
	}
}

int checkConnectedRange()
{
	int ret = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			if (!visited[i][j] && board[i][j] != 0)
			{
				if (bfs(Pair(i, j))) {
					ret++;
				}
			}
		}
	}
	return ret;
}

void eraseConnectedRegion()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			if (visited[i][j]) {
				board[i][j] = 0;
			}
		}
	}
}

void fillVisited() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 10; j++) {
			visited[i][j] = 0;
		}
	}
}

void solve()
{
	while (true)
	{
		fallDown();
		if (!checkConnectedRange()) break;
		else eraseConnectedRegion();
		fillVisited();
	}
}

void printBoard()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			cout << board[i][j];
		}
		cout << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	init();
	solve();
	printBoard();
	return 0;
}