#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

const int idx_1[] = { 0,0,1,-1 };
const int idx_2[] = { 1,-1,0,0 };

typedef pair<pair<int, int>, int>Pair;

int N, M;
int board[1001][1001];
int visited[1001][1001][2];
int step[1001][1001];

void init()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		string str;
		cin >> str;
		
		for (int j = 1; j <= M; j++)
		{
			board[i][j] = str[j - 1] - '0';
		}
	}
}

void bfs()
{
	queue<Pair>q;
	q.push(Pair(make_pair(1, 1), 0));
	visited[1][1][0] = 1;
	step[1][1] = 1;

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();

		if (pos.first == make_pair(N, M)) {
			cout << step[N][M] << endl;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			pair<int, int>next = make_pair(pos.first.first + idx_1[i], pos.first.second + idx_2[i]);

			if (next.first<1 || next.first>N || next.second<1 || next.second>M) continue;

			if (!visited[next.first][next.second][pos.second])
			{
				if (board[next.first][next.second] == 0)
				{
					q.push(Pair(next, pos.second));
					visited[next.first][next.second][pos.second] = 1;
					step[next.first][next.second] = step[pos.first.first][pos.first.second] + 1;
				}
				else
				{
					if (pos.second == 0)
					{
						q.push(Pair(next, 1));
						visited[next.first][next.second][1] = 1;
						step[next.first][next.second] = step[pos.first.first][pos.first.second] + 1;
					}
				}
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
	bfs();
	return 0;
}