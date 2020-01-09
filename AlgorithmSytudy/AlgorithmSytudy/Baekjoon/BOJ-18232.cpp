#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

int N, M, S, E;

vector<Pair>GP[300001];
int visited[300001];
int step[300001];

void init()
{
	cin >> N >> M;
	cin >> S >> E;

	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		GP[x].push_back(Pair(y, 1));
		GP[y].push_back(Pair(x, 1));
	}
}

void bfs()
{
	queue<int>q;
	q.push(S);
	visited[S] = 1;

	while (q.empty() != true)
	{
		int pos = q.front();
		q.pop();

		if (pos == E) {
			cout << step[pos] << endl;
			return;
		}

		for (int i = 0, next = 0; i < 3; i++)
		{
			if (i == 0)
			{
				next = pos - 1;

				if (next < 1) continue;
				if (visited[next] == 0)
				{
					q.push(next);
					visited[next] = 1;
					step[next] = step[pos] + 1;
				}
			}
			else if (i == 1)
			{
				next = pos + 1;

				if (next > N) continue;

				if (visited[next] == 0)
				{
					q.push(next);
					visited[next] = 1;
					step[next] = step[pos] + 1;
				}
			}
			else
			{
				for (auto elem : GP[pos])
				{
					next = elem.first;
					if (visited[next] == 0)
					{
						q.push(next);
						visited[next] = 1;
						step[next] = step[pos] + 1;
					}
				}
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
	bfs();
	return 0;
}