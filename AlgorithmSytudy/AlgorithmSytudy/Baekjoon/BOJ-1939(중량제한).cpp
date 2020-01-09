#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;
typedef pair<int, pair<int, int>> MST_Pair;

vector<Pair>GP[100001];
vector<MST_Pair>edges;
vector<int>visited(100001);
int parent[100001];
int N, M;
int start, goal;
int answer;

bool comp(MST_Pair p1, MST_Pair p2) {
	return p1.first > p2.first ? true : false;
}

int getParent(int idx) {
	if (idx == parent[idx]) return idx;
	else return getParent(parent[idx]);
}

void merge(int idx1, int idx2)
{
	int p1 = getParent(idx1);
	int p2 = getParent(idx2);

	parent[p1] = p2;
}

void init_1()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		GP[a].push_back(Pair(b, c));
		GP[b].push_back(Pair(a, c));
	}

	cin >> start >> goal;
}

void init_2()
{
	cin >> N >> M;

	for (int i = 0; i <= N; i++) parent[i] = i;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back(MST_Pair(c, Pair(a, b)));
	}

	cin >> start >> goal;
	sort(edges.begin(), edges.end(),comp);
}

bool dfs(int pos, int weight)
{
	if (pos == goal)
		return true;

	visited[pos] = true;

	for (auto next : GP[pos])
	{
		if (!visited[next.first] && weight <= next.second) {
			if (dfs(next.first, weight)) return true;
		}
	}
	return false;
}

bool bfs(int start, int weight)
{
	queue<int>q;
	q.push(start);
	visited[start] = true;

	while (q.empty() != true)
	{
		int pos = q.front();
		q.pop();

		if (pos == goal)
			return true;

		for (auto next : GP[pos])
		{
			if (!visited[next.first] && weight <= next.second)
			{
				visited[next.first] = true;
				q.push(next.first);
			}
		}
	}
	return false;
}

void solve_1()
{
	init_1();

	int left = 1, right = 1000000000;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (bfs(start, mid))
		{
			//다리 통과
			answer = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
		fill(visited.begin(), visited.end(), false);
	}
}

void solve_2()
{
	init_2();

	for (auto edge : edges)
	{
		int v1 = edge.second.first;
		int v2 = edge.second.second;

		if (getParent(v1) != getParent(v2))
		{
			merge(v1, v2);
		}

		if (getParent(start) == getParent(goal)) {
			cout << edge.first << endl;
			return;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	solve_2();
	return 0;
}