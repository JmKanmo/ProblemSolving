#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, vector<int>>Board_Pajr;
typedef pair<pair<int, int>, int>Tree_Pair;

const int idx1[] = { -1,-1,-1,0,0,1,1,1 };
const int idx2[] = { -1,0,1,-1,1,-1,0,1 };

int N, M, K;

Board_Pajr board[11][11];
int robot_arr[11][11];

void four_season()
{
	queue<Tree_Pair>dead_Tree;
	queue<pair<int, int>> spread_Tree;

	//spring
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int vitamin = board[i][j].first;

			for (int k = 0; k < board[i][j].second.size(); k++)
			{
				int tree_age = board[i][j].second[k];

				if (board[i][j].first >= tree_age)
				{
					board[i][j].first -= tree_age;
					board[i][j].second[k] += 1;
				}
				else {
					board[i][j].second.erase(board[i][j].second.begin() + k);
					k -= 1;
					dead_Tree.push(Tree_Pair(make_pair(i, j), tree_age));
				}
			}
			sort(board[i][j].second.begin(), board[i][j].second.end());
			if (board[i][j].second.empty() != true && board[i][j].second.back() >= 5) {
				spread_Tree.push(make_pair(i, j));
			}
		}
	}

	//summer
	while(dead_Tree.empty()!=true)
	{
		pair<int, int> pos = dead_Tree.front().first;
		int age = dead_Tree.front().second;
		board[pos.first][pos.second].first += (age / 2);
		dead_Tree.pop();
	}

	//april
	while (spread_Tree.empty()!=true) {
		pair<int, int> spread_pos = spread_Tree.front();

		for (int k = 0; k < board[spread_pos.first][spread_pos.second].second.size(); k++)
		{
			int age = board[spread_pos.first][spread_pos.second].second[k];

			if (age % 5 == 0)
			{
				for (int dir = 0; dir < 8; dir++)
				{
					pair<int, int>next = make_pair(spread_pos.first + idx1[dir], spread_pos.second + idx2[dir]);
					if (next.first<1 || next.first>N || next.second<1 || next.second>N) continue;
					board[next.first][next.second].second.push_back(1);
				}
			}
		}
		spread_Tree.pop();
	}
	
	//winter
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			board[i][j].first += robot_arr[i][j];
			sort(board[i][j].second.begin(), board[i][j].second.end());
		}
	}
}

int treetech()
{
	int tree_count = 0;
	int year = 0;

	while (year < K)
	{
		four_season();
		year++;
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			tree_count += board[i][j].second.size();

	return tree_count;
}

int main()
{
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &robot_arr[i][j]);
			board[i][j].first = 5;
		}
	}

	for (int i = 1; i <= M; i++)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		board[x][y].second.push_back(z);
		sort(board[x][y].second.begin(), board[x][y].second.end());
	}

	cout << treetech() << endl;
	return 0;
}