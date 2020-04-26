#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

typedef pair<int, int> Pair;

int N;
vector<Pair>GP[100001];
vector<int>visited(100001);
map<int, int>hash_map;
map<int, int>answer_map;

void dfs(int idx)
{
	visited[idx] = 1;

	for (auto elem : GP[idx])
	{
		if (!visited[elem.first])
		{
			hash_map[elem.first] = idx;
			dfs(elem.first);
		}
	}
}

void bfs()
{
	queue<int>q;
	q.push(1);
	visited[1] = 1;

	while (q.empty() != true)
	{
		int pos = q.front();
		q.pop();

		for (auto elem : GP[pos])
		{
			int next = elem.first;

			if (visited[next] == 0)
			{
				q.push(next);
				hash_map[next] = pos;
				visited[next] = 1;
			}
		}
	}
}

void init()
{
	cin >> N;

	for (int i = 1; i <= N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		GP[a].push_back(Pair(b, 1));
		GP[b].push_back(Pair(a, 1));
	}
}

void answer() {
	for (auto elem : hash_map) {
		answer_map[elem.first] = elem.second;
	}

	for (auto elem : answer_map) {
		cout << elem.second << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	init();
	bfs();
	answer();
	return 0;
}