#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

vector<Pair>GP[10001];
int visited[10001];
long long answer, idx;

void dfs(long long dist, int vertex)
{
	visited[vertex] = 1;

	if (dist > answer)
	{
		answer = dist;
		idx = vertex;
	}

	for (auto elem : GP[vertex])
	{
		if (!visited[elem.first])
			dfs(dist + elem.second, elem.first);
	}
}

void bfs(int start)
{
	queue<Pair>q;
	q.push(Pair(start, 0));
	visited[start] = 1;

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();

		if (answer < pos.second)
		{
			answer = pos.second;
			idx = pos.first;
		}

		for (auto elem : GP[pos.first])
		{
			if (!visited[elem.first])
			{
				visited[elem.first] = 1;
				q.push(Pair(elem.first, pos.second + elem.second));
			}
		}
	}
}

int main()
{
	int a, b, c;

	while (scanf("%d %d %d", &a, &b, &c) != EOF)
	{
		GP[a].push_back(Pair(b, c));
		GP[b].push_back(Pair(a, c));
	}

	bfs(a);
	memset(visited, 0, sizeof(visited));
	bfs(idx);
	cout << answer << endl;

	return 0;
}