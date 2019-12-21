#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int>> Pair;

const int INF = 2e9;

const int idx1[] = { 0,0,1,-1 };
const int idx2[] = { 1,-1,0,0 };

vector<vector<int>>board;
vector<vector<int>>distances;
priority_queue<Pair, vector<Pair>, greater<Pair>>pq;

int N;

void dijkstra()
{
	pq.push(Pair(board[1][1], make_pair(1, 1)));
	distances[1][1] = board[1][1];

	while (pq.empty() != true)
	{
		Pair elem = pq.top();
		pq.pop();

		int weight = elem.first;
		pair<int, int>pos = elem.second;
		

		for (int i = 0; i < 4; i++)
		{
			pair<int, int>next = make_pair(pos.first + idx1[i], pos.second + idx2[i]);

			if (next.first<1 || next.first> N || next.second<1 || next.second>N) 
				continue;

			int next_weight = weight + board[next.first][next.second];

			if (next_weight < distances[next.first][next.second])
			{
				distances[next.first][next.second] = next_weight;
				pq.push(Pair(next_weight, next));
			}
		}
	}
}

bool init()
{
	cin >> N;

	if (N == 0)
		return false;

	board = vector<vector<int>>(N + 1, vector<int>(N + 1));
	distances = vector<vector<int>>(N + 1, vector<int>(N + 1, INF));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> board[i][j];
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int t = 1;

	while (true)
	{
		if (init() == false) 
			break;
	
		dijkstra();
		cout << "Problem " << t << ": " << distances[N][N] << "\n";
		t++;
 	}

	return 0;
}