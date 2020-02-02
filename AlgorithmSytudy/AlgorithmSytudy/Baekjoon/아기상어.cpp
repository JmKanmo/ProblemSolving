#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> Pair;

const int idx_1[] = { 0,0,1,-1 };
const int idx_2[] = { 1,-1,0,0 };

int N;
int board[21][21];
int visited[21][21];
int step[21][21];
Pair shark_pos;
int shark_size = 2;
int hunting_cnt = 0;

void init()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 9) {
				shark_pos = Pair(i, j);
				board[i][j] = 0;
			}
		}
	}
}

int bfs()
{
	int min_distance = 2e9;
	memset(visited, 0, sizeof(visited));
	memset(step, 0, sizeof(step));

	queue<Pair>q;
	q.push(shark_pos);
	visited[shark_pos.first][shark_pos.second] = 1;

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Pair next = Pair(pos.first + idx_1[i], pos.second + idx_2[i]);

			if (next.first<1 || next.first>N || next.second<1 || next.second>N)
				continue;

			if (!visited[next.first][next.second] && board[next.first][next.second] <= shark_size)
			{
				q.push(next);
				visited[next.first][next.second] = 1;
				step[next.first][next.second] = step[pos.first][pos.second] + 1;
			}
		}
	}

	Pair target_pos;

	for (int i = N; i >= 1; i--)
	{
		for (int j = N; j >= 1; j--)
		{
			if (step[i][j] != 0 && board[i][j] != 0 && board[i][j] < shark_size && step[i][j] <= min_distance) {
				target_pos = Pair(i, j);
				min_distance = step[i][j];
			}
		}
	}

	shark_pos = target_pos;
	board[target_pos.first][target_pos.second] = 0;

	if (min_distance == 2e9) {
		return 0;
	}

	if (hunting_cnt + 1 == shark_size) {
		hunting_cnt = 0;
		shark_size++;
	}
	else {
		hunting_cnt++;
	}
	return min_distance;
}

int solve()
{
	int time = 0;

	while (true)
	{
		int cnt = bfs();
		if (cnt == 0)break;
		time += cnt;
	}

	return time;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	init();
	cout << solve() << endl;
	return 0;
}
