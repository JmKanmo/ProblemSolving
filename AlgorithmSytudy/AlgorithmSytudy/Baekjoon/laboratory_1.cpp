#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int idx1[] = { 0,0,1,-1 };
const int idx2[] = { 1,-1,0,0 };

vector<vector<int>>map(9, vector<int>(9));
vector<vector<bool>>visited;
vector<Pair>empty_pos;
vector<Pair>virus_pos;

int N, M;
int answer;
vector<int>temp(10);

int getCountOfSafeArea(vector<vector<int>>map)
{
	int cnt = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 0)
				cnt++;
		}
	}
	return cnt;
}

void bfs(vector<vector<int>>map)
{
	queue<Pair>q;

	visited = vector<vector<bool>>(9, vector<bool>(9));

	for (int i = 0; i < 3; i++) {
		map[empty_pos[temp[i]].first][empty_pos[temp[i]].second] = 1;
	}

	for (int i = 0; i < virus_pos.size(); i++)
	{
		visited[virus_pos[i].first][virus_pos[i].second] = true;
		q.push(virus_pos[i]);
	}

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Pair next = Pair(pos.first + idx1[i], pos.second + idx2[i]);

			if (next.first<1 || next.first>N || next.second<1 || next.second>M)
				continue;

			if (!visited[next.first][next.second] && map[next.first][next.second] == 0)
			{
				visited[next.first][next.second] = true;
				map[next.first][next.second] = 2;
				q.push(next);
			}
		}
	}
	answer = max(answer, getCountOfSafeArea(map));
}

void dfs(int n, int cnt)
{
	if (cnt == 3)
	{
		bfs(map);
		return;
	}

	for (int i = n; i < empty_pos.size(); i++)
	{
		temp[cnt] = i;
		dfs(i + 1, cnt + 1);
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) empty_pos.push_back(Pair(i, j));
			else if (map[i][j] == 2) virus_pos.push_back(Pair(i, j));
		}
	}

	dfs(0, 0);
	cout << answer << endl;
	return 0;
}