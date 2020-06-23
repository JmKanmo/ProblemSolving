#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int idx_1[] = {0,0,1,-1};
const int idx_2[] = {1,-1,0,0};

int N, M;
Pair junan, target;
char board[301][301];
int visited[301][301];

void init()
{
	cin >> N >> M;
	cin >> junan.first >> junan.second >> target.first >> target.second;

	for (int i = 1; i <= N; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= M; j++)
		{
			board[i][j] = str[j - 1];
		}
	}
}

bool bfs()
{
	queue<Pair>q;
	bool ret = false;
	q.push(junan);
	visited[junan.first][junan.second] = 1;

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();

		if (board[pos.first][pos.second] == '1') {
			board[pos.first][pos.second] = '0';
			continue;
		}

		if (board[pos.first][pos.second] == '#') {
			ret = true;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			Pair next = Pair(pos.first + idx_1[i], pos.second + idx_2[i]);

			if (next.first<1 || next.first>N || next.second<1 || next.second>M
				|| visited[next.first][next.second]) continue;

			q.push(next);
			visited[next.first][next.second] = 1;
		}
	}
	return ret;
}

void solve()
{
	int time = 0;
	
	while (++time)
	{
		if (bfs()) break;
		memset(visited, 0, sizeof(visited));
	}
	cout << time << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	init();
	solve();
	return 0;
}