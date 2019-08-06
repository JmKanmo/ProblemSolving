#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int idx1[] = { 0,0,1,-1 };
const int idx2[] = { 1,-1,0,0 };

const int INF = 987654321;
int N, virus_cnt, empty_cnt;
int min_time = INF;

vector<vector<int>>board(51, vector<int>(51));
vector<vector<bool>>visited;
vector<vector<int>>step;
vector<Pair>virus_pos;
vector<int>temp(11);

void bfs(vector<vector<int>>board, int empty_cnt)
{
	queue<Pair>q;
	int virus = 0;
	visited = vector<vector<bool>>(51, vector<bool>(51));
	step = vector<vector<int>>(51, vector<int>(51));

	for (int i = 0; i < virus_pos.size(); i++)
	{
		board[virus_pos[i].first][virus_pos[i].second] = -1;
	}

	for (int i = 0; i < virus_cnt; i++)
	{
		visited[virus_pos[temp[i]].first][virus_pos[temp[i]].second] = true;
		q.push(virus_pos[temp[i]]);
		virus++;
	}

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();

		if (min_time != INF && step[pos.first][pos.second] > min_time)
			return;

		for (int i = 0; i < 4; i++)
		{
			Pair next = Pair(pos.first + idx1[i], pos.second + idx2[i]);

			if (next.first<1 || next.first>N || next.second<1 || next.second>N)
				continue;

			if (!visited[next.first][next.second])
			{
				if (board[next.first][next.second] == 0) {
					visited[next.first][next.second] = true;
					step[next.first][next.second] = step[pos.first][pos.second] + 1;
					board[next.first][next.second] = 2;
					q.push(next);
					virus++;
				}
				else if (board[next.first][next.second] == -1)
				{
					visited[next.first][next.second] = true;
					step[next.first][next.second] = step[pos.first][pos.second] + 1;
					board[next.first][next.second] = -1;
					q.push(next);
					virus++;
				}
			}
		}
	}

	int MAX = 0;

	if (virus == empty_cnt) {
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if(board[i][j]!=-1)
				MAX = max(step[i][j], MAX);
		min_time = min(min_time, MAX);
	}
}

void dfs(int n, int cnt)
{
	if (cnt == virus_cnt)
	{
		bfs(board, empty_cnt);
		return;
	}

	for (int i = n; i < virus_pos.size(); i++) {
		temp[cnt] = i;
		dfs(i + 1, cnt + 1);
	}
}

int main()
{
	cin >> N >> virus_cnt;
	empty_cnt = N * N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &board[i][j]);
			if (board[i][j] == 2) virus_pos.push_back(Pair(i, j));
			else if (board[i][j] == 1) empty_cnt--;
		}
	}

	dfs(0, 0);
	if (min_time == INF) cout << -1 << endl;
	else
		cout << min_time << endl;
	return 0;
}