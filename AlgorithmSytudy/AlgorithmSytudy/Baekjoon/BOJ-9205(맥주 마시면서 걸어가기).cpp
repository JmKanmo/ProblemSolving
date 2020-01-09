#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

int N;
vector<Pair>board;
vector<int>visited;

void init()
{
	cin >> N;
	visited = vector<int>(N + 2);
	board.clear();

	for (int i = 0; i < N + 2; i++)
	{
		int x, y;
		cin >> x >> y;
		board.push_back(Pair(x, y));
	}
}

int getDistance(Pair pos1, Pair pos2)
{
	return abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
}

void bfs()
{
	queue<Pair>q;
	visited[0] = 1;
	q.push(board[0]);

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();

		if (pos == board[N + 1]) {
			cout << "happy" << endl;
			return;
		}

		for (int i = 0; i < N + 2; i++)
		{
			if (visited[i] == 0 && getDistance(pos,board[i])<=1000)
			{
				visited[i] = 1;
				q.push(board[i]);
			}
		}
	}
	cout << "sad" << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int test;
	cin >> test;

	for (int t = 0; t < test; t++)
	{
		init();
		bfs();
	}

	return 0;
}