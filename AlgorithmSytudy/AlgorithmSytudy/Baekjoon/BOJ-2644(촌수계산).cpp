#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

vector<Pair>GP[101];
int visited[101];
int step[101];
int find_a, find_b;
int answer;
int N, M;

void init()
{
	cin>> N;
	cin >> find_a >> find_b;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		GP[x].push_back(Pair(y, 1));
		GP[y].push_back(Pair(x, 1));
	}
}

void solve()
{
	queue<int>q;
	q.push(find_a);
	visited[find_a] = 1;

	while (q.empty() != true)
	{
		int pos = q.front();
		q.pop();

		if (pos == find_b) {
			cout << step[pos] << endl;
			return;
		}

		for (auto elem : GP[pos])
		{
			if (visited[elem.first] == 0)
			{
				visited[elem.first] = 1;
				step[elem.first] = step[pos] + 1;
				q.push(elem.first);
			}
		}
	}
	cout << -1 << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	init();
	solve();
	return 0;
}