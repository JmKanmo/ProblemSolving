#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<pair<int, int>, int> Pair;

const int idx1[] = { 0,0,1,-1 };
const int idx2[] = { 1,-1,0,0 };

char board[51][51];
int step[51][51][65];
int N, M;
pair<int, int>start;

void init()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= M; j++)
		{
			board[i][j] = str[j - 1];
			if (board[i][j] == '0') start = make_pair(i, j);
		}
	}
}

void bfs()
{
	queue<Pair>q;
	q.push(Pair(start, 0));

	while (q.empty() != true)
	{
		pair<int, int>pos = q.front().first;
		int keys = q.front().second;
		q.pop();

		if (board[pos.first][pos.second] == '1') {
			cout << step[pos.first][pos.second][keys] << endl;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			pair<int, int>next = make_pair(pos.first + idx1[i], pos.second + idx2[i]);

			if (next.first<1 || next.first>N || next.second<1 || next.second>M) continue;

			int next_key = board[next.first][next.second];
			int mod_keys = keys;

			if (isalpha(next_key))
			{
				if (islower(next_key))
				{
					// Å°
					mod_keys |= (1 << (next_key - 'a'));
				}
				else
				{
					// ¿­¼è
					if (!(mod_keys & (1 << (next_key - 'A')))) continue;
				}
			}

			if (board[next.first][next.second] != '#' && !step[next.first][next.second][mod_keys])
			{
				step[next.first][next.second][mod_keys] = step[pos.first][pos.second][keys] + 1;
				q.push(Pair(next, mod_keys));
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



