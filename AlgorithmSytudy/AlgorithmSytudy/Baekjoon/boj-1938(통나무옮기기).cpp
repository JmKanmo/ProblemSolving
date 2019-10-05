#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int>Pair;

const int idx1[] = { 0,0,1,-1 };
const int idx2[] = { 1,-1,0,0 };

struct Wood
{
	Pair front;
	Pair middle;
	Pair rear;
	int cnt;
	int dir; // 0-가로, 1-세로

	Wood() {}

	Wood(Pair front, Pair middle, Pair rear, int cnt, int dir)
	{
		this->front = front;
		this->middle = middle;
		this->rear = rear;
		this->cnt = cnt;
		this->dir = dir;
	}
};

int N;
int board[51][51];
bool visited[51][51][2];
vector<Pair>start;
vector<Pair>goal;

void init()
{
	scanf("%d", &N);
	getchar();

	for (int i = 1; i <= N; i++)
	{
		string str;
		cin >> str;

		for (int j = 1; j <= N; j++)
		{
			char ch = str[j - 1];

			if (ch == 'B')
			{
				start.push_back(Pair(i, j));
				board[i][j] = 0;
			}
			else if (ch == 'E')
			{
				goal.push_back(Pair(i, j));
				board[i][j] = 0;
			}
			else {
				board[i][j] = ch - '0';
			}
		}
	}
}

bool check(Pair front, Pair middle, Pair rear)
{
	if (board[front.first][front.second] || board[middle.first][middle.second] || board[rear.first][rear.second])
		return true;

	if (front.first<1 || front.first>N || front.second<1 || front.second>N
		|| middle.first<1 || middle.first>N || middle.second<1 || middle.second>N ||
		rear.first<1 || rear.first>N || rear.second<1 || rear.second>N) return true;

	return false;
}

int bfs()
{
	queue<Wood>q;
	q.push(Wood(start[0], start[1], start[2], 0, start[0].first == start[1].first && start[1].first == start[2].first && start[0].first == start[2].first ? 0 : 1));
	visited[start[0].first][start[0].second][start[0].first == start[1].first && start[1].first == start[2].first && start[0].first == start[2].first ? 0 : 1] = true;

	while (q.empty() != true)
	{
		Wood cur_wood = q.front();
		q.pop();

		if (cur_wood.front == goal[0] && cur_wood.middle == goal[1] && cur_wood.rear == goal[2])
			return cur_wood.cnt;

		//통나무이동
		for (int i = 0; i < 4; i++)
		{
			Wood next_wood = Wood(
				Pair(cur_wood.front.first + idx1[i], cur_wood.front.second + idx2[i]),
				Pair(cur_wood.middle.first + idx1[i], cur_wood.middle.second + idx2[i]),
				Pair(cur_wood.rear.first + idx1[i], cur_wood.rear.second + idx2[i]),
				cur_wood.cnt + 1, cur_wood.dir
			);

			if (check(next_wood.front, next_wood.middle, next_wood.rear))
				continue;

			if (!visited[next_wood.front.first][next_wood.front.second][next_wood.dir])
			{
				visited[next_wood.front.first][next_wood.front.second][next_wood.dir] = true;
				q.push(next_wood);
			}
		}

		//통나무회전(가로방향에서)
		if (cur_wood.dir == 0)
		{
			if (!check(Pair(cur_wood.front.first - 1, cur_wood.front.second), Pair(cur_wood.middle.first - 1, cur_wood.middle.second), Pair(cur_wood.rear.first - 1, cur_wood.rear.second))
				&& !check(Pair(cur_wood.front.first + 1, cur_wood.front.second), Pair(cur_wood.middle.first + 1, cur_wood.middle.second), Pair(cur_wood.rear.first + 1, cur_wood.rear.second)))
			{
				if (!visited[cur_wood.front.first - 1][cur_wood.front.second + 1][!cur_wood.dir])
				{
					Wood rotated_wood = Wood(
						Pair(cur_wood.front.first - 1, cur_wood.front.second + 1),
						cur_wood.middle,
						Pair(cur_wood.rear.first + 1, cur_wood.rear.second - 1),
						cur_wood.cnt + 1,
						!cur_wood.dir
					);
					visited[cur_wood.front.first - 1][cur_wood.front.second + 1][!cur_wood.dir] = true;
					q.push(rotated_wood);
				}
			}
		}
		//세로방향에서
		else
		{
			if (!check(Pair(cur_wood.front.first, cur_wood.front.second - 1), Pair(cur_wood.middle.first, cur_wood.middle.second - 1), Pair(cur_wood.rear.first, cur_wood.rear.second - 1))
				&& !check(Pair(cur_wood.front.first, cur_wood.front.second + 1), Pair(cur_wood.middle.first, cur_wood.middle.second + 1), Pair(cur_wood.rear.first, cur_wood.rear.second + 1)))
			{
				if (!visited[cur_wood.front.first + 1][cur_wood.front.second - 1][!cur_wood.dir])
				{
					Wood rotated_wood = Wood(
						Pair(cur_wood.front.first + 1, cur_wood.front.second - 1),
						cur_wood.middle,
						Pair(cur_wood.rear.first - 1, cur_wood.rear.second + 1),
						cur_wood.cnt + 1, !cur_wood.dir
					);
					visited[cur_wood.front.first + 1][cur_wood.front.second - 1][!cur_wood.dir] = true;
					q.push(rotated_wood);
				}
			}
		}
	}
	return 0;
}

int main()
{
	init();
	printf("%d\n", bfs());
	return 0;
}