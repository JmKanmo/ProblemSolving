#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int>> Pair;

const int horse_idx1[] = { -1,-2,-2,-1,1,2,2,1 };
const int horse_idx2[] = { -2,-1,1,2,-2,-1,1,2 };
const int monkey_idx1[] = { 0,0,1,-1 };
const int monkey_idx2[] = { 1,-1,0,0 };

int K;
int W, H;
int board[201][201];
int visited[201][201][32];
int steps[201][201][32];

void init()
{
	cin >> K;
	cin >> W >> H;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> board[i][j];
		}
	}
}

void bfs()
{
	queue<Pair>q;
	q.push(Pair(0, make_pair(1, 1)));
	visited[1][1][0] = 1;

	while (q.empty() != true)
	{
		Pair elem = q.front();
		q.pop();
		int step = elem.first;
		pair<int, int> pos = elem.second;

		if (pos.first == H && pos.second == W) {
			cout << visited[pos.first][pos.second][step] - 1 << endl;
			return;
		}

		if (step < K)
		{
			for (int i = 0; i < 8; i++)
			{
				pair<int, int> next = make_pair(pos.first + horse_idx1[i], pos.second + horse_idx2[i]);

				if (next.first<1 || next.first>H || next.second<1 || next.second>W
					|| visited[next.first][next.second][step + 1] || board[next.first][next.second]) continue;

				visited[next.first][next.second][step + 1] = 1;
				q.push(Pair(step + 1, next));
			}
		}
		for (int i = 0; i < 4; i++)
		{
			pair<int, int> next = make_pair(pos.first + monkey_idx1[i], pos.second + monkey_idx2[i]);

			if (next.first<1 || next.first>H || next.second<1 || next.second>W
				|| visited[next.first][next.second][step] || board[next.first][next.second]) continue;

			visited[next.first][next.second][step] = 1;
			q.push(Pair(step, next));
		}
	}
	cout << -1 << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	init();
	bfs();
	return 0;
}