#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int idx1[] = { 0,0,1,-1 };
const int idx2[] = { 1,-1,0,0 };

typedef pair<int, int> Pair;

int N, M;
int board[301][301];
vector<vector<int>>visited;

void init()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> board[i][j];
		}
	}
}

int getVal(Pair pos)
{
	int ret = 0;

	for (int i = 0; i < 4; i++)
	{
		Pair next = Pair(pos.first + idx1[i], pos.second + idx2[i]);

		if (next.first<1 || next.first>N || next.second<1 || next.second>M)
			continue;

		if (board[next.first][next.second] == 0) ret++;
	}
	return ret;
}

void ice_break()
{
	vector<vector<int>>temp = vector<vector<int>>(N + 1, vector<int>(M + 1));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (board[i][j] != 0)
			{
				temp[i][j] = getVal(Pair(i, j));
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			board[i][j] -= temp[i][j];
			if (board[i][j] < 0) board[i][j] = 0;
		}
	}
}

void bfs(Pair start, int step)
{
	queue<Pair>q;
	q.push(start);
	visited[start.first][start.second] = step;

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Pair next = Pair(pos.first + idx1[i], pos.second + idx2[i]);

			if (next.first<1 || next.first>N || next.second<1 || next.second>M)
				continue;

			if (board[next.first][next.second] != 0 && visited[next.first][next.second] == 0)
			{
				visited[next.first][next.second] = step;
				q.push(next);
			}
		}
	}
}

bool isSeperated()
{
	int step = 0;
	visited = vector<vector<int>>(N + 1, vector<int>(M + 1));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (board[i][j] != 0 && visited[i][j] == 0) {
				bfs(Pair(i, j), ++step);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (visited[i][j] > 1)
				return  true;
		}
	}
	return false;
}

bool isZero()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (board[i][j] != 0)
				return false;
		}
	}
	return true;
}

int solve()
{
	int time = 0;

	while (true)
	{
		if (isSeperated())
			break;
		else {
			if (isZero()) 
				return 0;
		}
		ice_break();
		time++;
	}
	return time;
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