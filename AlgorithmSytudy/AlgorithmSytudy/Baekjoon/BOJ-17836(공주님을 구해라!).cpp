#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<pair<int, int>, bool> Pair;

const int idx1[] = { 0,0,1,-1 };
const int idx2[] = { 1,-1,0,0 };

struct Visited {
	int hasGram[101][101];
	int unhasGram[101][101];
};

int N, M, T;
int board[101][101];
Visited visited;

void init()
{
	cin >> N >> M >> T;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> board[i][j];
		}
	}
}

bool bfs(Pair start)
{
	queue<Pair>q;
	q.push(start);
	visited.unhasGram[start.first.first][start.first.second] = 1;

	for (int time = 0; time <= T; time++)
	{
		int q_size = q.size();

		while (q_size--)
		{
			pair<int, int>pos = q.front().first;
			bool flag = q.front().second;
			q.pop();

			if (pos == make_pair(N, M)) {
				cout << time << endl;
				return true;
			}

			if (board[pos.first][pos.second] == 2) {
				visited.hasGram[pos.first][pos.second] = true;
				flag = true;
			}

			for (int i = 0; i < 4; i++)
			{
				pair<int, int> next = make_pair(pos.first + idx1[i], pos.second + idx2[i]);

				if (next.first<1 || next.first>N || next.second<1 || next.second>M)
					continue;

				if (flag)
				{
					if (!visited.hasGram[next.first][next.second])
					{
						q.push(Pair(next, flag));
						visited.hasGram[next.first][next.second] = true;
					}
				}
				else
				{
					if (!visited.unhasGram[next.first][next.second])
					{
						if (board[next.first][next.second] != 1)
						{
							q.push(Pair(next, flag));
							visited.unhasGram[next.first][next.second] = true;
						}
					}
				}
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	init();
	if (!bfs(Pair(make_pair(1, 1), false))) cout << "Fail" << endl;
	return 0;
}