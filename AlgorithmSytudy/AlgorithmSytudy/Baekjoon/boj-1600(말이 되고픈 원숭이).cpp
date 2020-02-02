#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<pair<int, int>, int> Pair;

const int idx_1[] = { 0,0,1,-1 };
const int idx_2[] = { 1,-1,0,0 };
const int idx_3[] = { -1,-2,-2,-1,1,2,2,1 };
const int idx_4[] = { -2,-1,1,2,-2,-1,1,2 };

int K;
int W, H;
int board[201][201];
int visited[201][201][31];
int step[201][201][31];

void init()
{
	cin >> K;
	cin >> W >> H;

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			cin >> board[i][j];
		}
	}
}

bool check_range(pair<int, int>pos) {
	if (pos.first<1 || pos.first>H || pos.second<1 || pos.second>W) return true;
	else return false;
}

int bfs()
{
	queue<Pair>q;
	q.push(Pair(make_pair(1, 1), 0));
	visited[1][1][0] = 1;

	while (q.empty() != true)
	{
		Pair elem = q.front();
		pair<int, int> pos = elem.first;
		int cnt = elem.second;
		q.pop();

		if (pos == make_pair(H, W))
		{
			return step[H][W][cnt];
		}

		if (cnt < K)
		{
			for (int i = 0; i < 8; i++)
			{
				pair<int, int>next_pos = make_pair(pos.first + idx_3[i], pos.second + idx_4[i]);
				if (check_range(next_pos)) continue;
				if (!visited[next_pos.first][next_pos.second][cnt + 1] && board[next_pos.first][next_pos.second] == 0)
				{
					visited[next_pos.first][next_pos.second][cnt + 1] = 1;
					q.push(Pair(next_pos, cnt + 1));
					step[next_pos.first][next_pos.second][cnt + 1] = step[pos.first][pos.second][cnt] + 1;
				}
			}
		}

		for (int i = 0; i < 4; i++)
		{
			pair<int, int>next_pos = make_pair(pos.first + idx_1[i], pos.second + idx_2[i]);
			if (check_range(next_pos)) continue;
			if (!visited[next_pos.first][next_pos.second][cnt] && board[next_pos.first][next_pos.second] == 0)
			{
				visited[next_pos.first][next_pos.second][cnt] = 1;
				q.push(Pair(next_pos, cnt));
				step[next_pos.first][next_pos.second][cnt] = step[pos.first][pos.second][cnt] + 1;
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	init();
	cout << bfs() << endl;
	return 0;
}