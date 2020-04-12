#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

struct Pos
{
	int x, y;
	int dir;

	Pos() {}

	Pos(int x, int y, int dir) {
		this->x = x;
		this->y = y;
		this->dir = dir;
	}
};

const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

const int INF = 2e9;

int N;
int answer = 2e9;
char board[51][51];
int visited[51][51][5];
vector<Pair>start;

void init()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		string str;
		cin >> str;

		for (int j = 1; j <= N; j++)
		{
			board[i][j] = str[j - 1];

			if (board[i][j] == '#')
				start.push_back(Pair(i, j));
		}
	}

	for (int i = 0; i <= 50; i++) {
		for (int j = 0; j <= 50; j++) {
			for (int k = 0; k <= 4; k++) {
				visited[i][j][k] = 2e9;
			}
		}
	}
}

Pair changeDir(int dir)
{
	Pair ret;

	if (dir == 0 || dir == 1)
	{
		ret.first = 2;
		ret.second = 3;
	}
	else
	{
		ret.first = 0;
		ret.second = 1;
	}
	return ret;
}

void  bfs()
{
	queue<Pos>q;

	for (int i = 0; i < 4; i++)
	{
		Pos temp;
		temp.x = start[0].first;
		temp.y = start[0].second;
		temp.dir = i;
		q.push(temp);
		visited[temp.x][temp.y][temp.dir] = 0;
	}

	while (q.empty() != true)
	{
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		q.pop();

		int nx = x + dx[dir];
		int ny = y + dy[dir];
		Pair nextDir = changeDir(dir);

		if (nx<1 || nx>N || ny<1 || ny>N)
			continue;

		if (board[nx][ny] == '*')
			continue;
		else if (board[nx][ny] == '!')
		{
			if (visited[nx][ny][dir] > visited[x][y][dir])
			{
				visited[nx][ny][dir] = visited[x][y][dir];
				q.push(Pos(nx, ny, dir));
			}

			if (visited[nx][ny][nextDir.first] > visited[x][y][dir] + 1)
			{
				visited[nx][ny][nextDir.first] = visited[x][y][dir] + 1;
				q.push(Pos(nx, ny, nextDir.first));
			}

			if (visited[nx][ny][nextDir.second] > visited[x][y][dir] + 1)
			{
				visited[nx][ny][nextDir.second] = visited[x][y][dir] + 1;
				q.push(Pos(nx, ny, nextDir.second));
			}
		}
		else if (board[nx][ny] == '.') {
			if (visited[nx][ny][dir] > visited[x][y][dir])
			{
				visited[nx][ny][dir] = visited[x][y][dir];
				q.push(Pos(nx, ny, dir));
			}
		}
		else if (board[nx][ny] == '#') {
			if (visited[nx][ny][dir] > visited[x][y][dir])
			{
				visited[nx][ny][dir] = visited[x][y][dir];
				q.push(Pos(nx, ny, dir));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();
	bfs();
	for (int i = 0; i < 4; i++) {
		if (answer > visited[start[1].first][start[1].second][i]) {
			answer = visited[start[1].first][start[1].second][i];
		}
	}
	cout << answer << endl;
	return 0;
}