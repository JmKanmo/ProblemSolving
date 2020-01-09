#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int idx_1[] = { 0,0,1,-1 };
const int idx_2[] = { 1,-1,0,0 };

char board[6][6];
int visited[6][6];
char arr[26];
int answer;

void init()
{
	for (int i = 0, cnt = 0; i < 5; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < 5; j++)
		{
			board[i][j] = str[j];
			arr[cnt++] = str[j];
		}
	}
}

bool bfs(Pair start)
{
	queue<Pair>q;
	int dasom = 0;
	int cnt = 0;
	int temp_visited[6][6] = { 0, };

	q.push(start);
	temp_visited[start.first][start.second] = 1;

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();
		if (board[pos.first][pos.second] == 'S') dasom++;
		cnt++;

		for (int i = 0; i < 4; i++)
		{
			Pair next = Pair(pos.first + idx_1[i], pos.second + idx_2[i]);

			if (next.first < 0 || next.first >= 5 || next.second < 0 || next.second >= 5)
				continue;

			if (visited[next.first][next.second] && temp_visited[next.first][next.second] == 0)
			{
				temp_visited[next.first][next.second] = 1;
				q.push(next);
			}
		}
	}
	return cnt >= 7 && dasom >= 4 ? true : false;
}

void dfs(int idx, int cnt, vector<int>v)
{
	if (cnt >= 7)
	{
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < v.size(); i++)
			visited[v[i] / 5][v[i] % 5] = 1;

		if (bfs(Pair(v[0] / 5, v[0] % 5)))
			answer++;
		return;
	}

	for (int i = idx + 1; i <= 25; i++)
	{
		v.push_back(i);
		dfs(i, cnt + 1, v);
		v.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	init();
	dfs(-1, 0, {});
	cout << answer << endl;
	return 0;
}

