#include <iostream>
#include <queue>

#define MAX 351

using namespace std;

typedef pair<int, int> Pair;

const int idx1[] = { 0,0,1,-1 };
const int idx2[] = { 1,-1,0,0 };

struct Cell
{
	int living_time = 0; // 생존기간
	int hp = 0; //생명력수치
};

int N, M, K;
int answer;
vector<vector<Cell>>board;
queue<Pair>q[11];

void init()
{
	answer = 0;
	board = vector<vector<Cell>>(MAX, vector<Cell>(MAX));

	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int vital;
			scanf("%d", &vital);
			board[i + 150][j + 150].hp = vital;
			board[i + 150][j + 150].living_time = vital * 2;
			q[vital].push(Pair(i + 150, j + 150));
		}
	}
}

void solve()
{
	while (K--)
	{
		for (int i = 10; i >= 1; i--)
		{
			int q_size = q[i].size();

			while (q_size--)
			{
				Pair pos = q[i].front();
				q[i].pop();
				board[pos.first][pos.second].living_time--;

				if (board[pos.first][pos.second].living_time < board[pos.first][pos.second].hp)
				{
					for (int idx = 0; idx < 4; idx++)
					{
						Pair next_pos = Pair(pos.first + idx1[idx], pos.second + idx2[idx]);

						if (board[next_pos.first][next_pos.second].hp == 0)
						{
							board[next_pos.first][next_pos.second].hp = board[pos.first][pos.second].hp;
							board[next_pos.first][next_pos.second].living_time = board[pos.first][pos.second].hp * 2;
							q[i].push(next_pos);
						}
					}
				}
				if (board[pos.first][pos.second].living_time > 0)
					q[i].push(pos);
			}
		}
	}

	for (int i = 1; i <= 10; i++)
	{
		answer += q[i].size();
		while (q[i].empty() != true) q[i].pop();
	}
}

int main()
{
	int test;
	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		init();
		solve();
		printf("#%d %d\n", t, answer);
	}
	return 0;
}