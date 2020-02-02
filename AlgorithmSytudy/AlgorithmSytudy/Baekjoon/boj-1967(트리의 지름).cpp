#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

vector<Pair>GP[10001];
int visited[10001];
int N;
int idx;
int answer;

void init()
{
	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		GP[a].push_back(Pair(b, c));
		GP[b].push_back(Pair(a, c));
	}
}

void dfs(int dist, int vertex)
{
	visited[vertex] = 1;

	if (answer < dist)
	{
		answer = dist;
		idx = vertex;
	}

	for (auto elem : GP[vertex])
	{
		if (!visited[elem.first])
		{
			dfs(dist + elem.second, elem.first);
		}
	}
}

void bfs(int start)
{
	queue<Pair>q;
	q.push(Pair(start, 0));
	visited[start] = 0;

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();

		if (pos.second > answer)
		{
			answer = pos.second;
			idx = pos.first;
		}

		for (auto next : GP[pos.first])
		{
			if (!visited[next.first])
			{
				visited[next.first] = 1;
				q.push(Pair(next.first, pos.second + next.second));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	init();
	bfs(1);
	memset(visited, 0, sizeof(visited));
	bfs(idx);
	cout << answer << endl;
	return 0;
}