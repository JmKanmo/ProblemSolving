#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int F, S, G, U, D;

int visited[1000001];
int step[1000001];

void bfs()
{
	queue<int>q;
	q.push(S);
	visited[S] = 1;

	while (q.empty() != true)
	{
		int pos = q.front();
		q.pop();

		if (pos == G)
		{
			cout << step[pos] << "\n";
			return;
		}

		for (int i = 0; i < 2; i++)
		{
			if (i == 0)
			{
				int next = pos + U;

				if (next <= F && !visited[next])
				{
					q.push(next);
					visited[next] = 1;
					step[next] = step[pos] + 1;
				}
			}
			else
			{
				int next = pos - D;

				if (next >= 1 && !visited[next])
				{
					q.push(next);
					visited[next] = 1;
					step[next] = step[pos] + 1;
				}
			}
		}
	}
	cout << "use the stairs" << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> F >> S >> G >> U >> D;
	bfs();

	return 0;
}