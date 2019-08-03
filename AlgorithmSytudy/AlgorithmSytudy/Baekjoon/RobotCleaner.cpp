#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int idx1[] = { 0,0,1,-1 }; //동서남북
const int idx2[] = { 1,-1,0,0 };

int n, m;

int board[51][51];
int visited[51][51];

bool search(Pair robot_pos)
{
	bool ret = false;

	for (int i = 0; i < 4; i++) {
		Pair next = Pair(robot_pos.first + idx1[i], robot_pos.second + idx2[i]);
		if (visited[next.first][next.second] != 1 && board[next.first][next.second] != 1) {
			ret = true;
			return ret;
		}
	}
	return ret;
}

Pair getRotatedPos(Pair robot_pos, int robot_way)
{
	Pair next_pos;

	if (robot_way == 0) next_pos = Pair(robot_pos.first, robot_pos.second - 1);
	else if (robot_way == 1) next_pos = Pair(robot_pos.first - 1, robot_pos.second);
	else if (robot_way == 2) next_pos = Pair(robot_pos.first, robot_pos.second + 1);
	else next_pos = Pair(robot_pos.first + 1, robot_pos.second);
	return next_pos;
}

int getRocatedWay(int robot_way)
{
	switch (robot_way)
	{
	case 0: return robot_way = 3;
	case 1: return robot_way = 0;
	case 2:	return robot_way = 1;
	case 3: return robot_way = 2;
	}
}

bool left_rotate(Pair robot_pos, int robot_way) {
	bool ret = true;
	Pair rocatedPos = getRotatedPos(robot_pos, robot_way);

	if (visited[rocatedPos.first][rocatedPos.second] == true || board[rocatedPos.first][rocatedPos.second] == 1) {
		ret = false;
	}
	return ret;
}

Pair back(Pair robot_pos, int robot_way)
{
	Pair next_pos;

	if (robot_way == 0) 
		next_pos = Pair(robot_pos.first + 1, robot_pos.second);
	else if (robot_way == 1) 
		next_pos = Pair(robot_pos.first, robot_pos.second - 1);
	else if (robot_way == 2) 
		next_pos = Pair(robot_pos.first - 1, robot_pos.second);
	else 
		next_pos = Pair(robot_pos.first, robot_pos.second + 1);

	return next_pos;
}

void clean(Pair robot_pos, int robot_way)
{
	visited[robot_pos.first][robot_pos.second] = 1;

	while (true)
	{
		if (search(robot_pos)) {
			if (left_rotate(robot_pos, robot_way)) {
				robot_pos = getRotatedPos(robot_pos, robot_way);
				robot_way = getRocatedWay(robot_way);
				visited[robot_pos.first][robot_pos.second] = true;
			}
			else {
				robot_way = getRocatedWay(robot_way);
			}
		}
		else {
			//현재 바라보는방향에서 뒤쪽방향 탐색후 종료여부결정
			robot_pos = back(robot_pos, robot_way);
			if (board[robot_pos.first][robot_pos.second] == 1) break;
		}
	}
}

int getCntOfClean()
{
	int cnt = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cnt = visited[i][j] == 1 ? cnt + 1 : cnt;

	return cnt;
}

int main()
{	
	int a, b;
	Pair robot_pos;
	int robot_way;

	cin >> n >> m;
	cin >> a >> b >> robot_way;
	robot_pos.first += (1 + a);
	robot_pos.second += (1 + b);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &board[i][j]);

	clean(robot_pos, robot_way);
	cout << getCntOfClean() << endl;
	return 0;
}