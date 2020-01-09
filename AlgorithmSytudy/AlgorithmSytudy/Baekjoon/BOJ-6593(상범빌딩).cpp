#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int>>Pos_Pair; // Ãþ, (idx_1,idx_2)

const int idx_1[] = { 0,0,0,0,1,-1 };
const int idx_2[] = { 0,0,1,-1,0,0 };
const int idx_3[] = { 1,-1,0,0,0,0 };

int L, R, C;
char board[31][31][31];
int visited[31][31][31];
int step[31][31][31];
Pos_Pair start, goal;

void init()
{
	memset(visited, 0, sizeof(visited));
	memset(step, 0, sizeof(step));

	for (int i = 1; i <= L; i++)
	{
		for (int j = 1; j <= R; j++)
		{
			string str;
			cin >> str;

			for (int k = 1; k <= C; k++)
			{
				board[i][j][k] = str[k - 1];

				if (board[i][j][k] == 'S') start = Pos_Pair(i, make_pair(j, k));
				else if (board[i][j][k] == 'E') goal = Pos_Pair(i, make_pair(j, k));
			}
		}
	}
}

bool isAccessRange(Pos_Pair pos) {
	if ((pos.first<1 || pos.first>L) || (pos.second.first<1 || pos.second.first>R) || (pos.second.second<1 || pos.second.second>C)) return true;
	else return false;
}

void bfs()
{
	queue<Pos_Pair>q;
	q.push(start);
	visited[start.first][start.second.first][start.second.second] = 1;

	while (q.empty() != true)
	{
		Pos_Pair pos = q.front();
		q.pop();

		if (pos == goal) {
			cout << "Escaped in " << step[pos.first][pos.second.first][pos.second.second] << " minute(s)." << endl;
			return;
		}

		for (int i = 0; i < 6; i++)
		{
			Pos_Pair next = Pos_Pair(pos.first + idx_1[i], make_pair(pos.second.first + idx_2[i], pos.second.second + idx_3[i]));

			if (isAccessRange(next)) continue;

			if (visited[next.first][next.second.first][next.second.second] == 0 && board[next.first][next.second.first][next.second.second] != '#')
			{
				q.push(next);
				visited[next.first][next.second.first][next.second.second] = 1;
				step[next.first][next.second.first][next.second.second] = step[pos.first][pos.second.first][pos.second.second] + 1;
			}
		}
	}
	cout << "Trapped!" << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	while (true)
	{
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;
		init();
		bfs();
	}
	return 0;
}