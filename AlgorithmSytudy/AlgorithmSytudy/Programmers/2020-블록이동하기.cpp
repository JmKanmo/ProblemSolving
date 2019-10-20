#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int idx1[] = { 0,0,1,-1 };
const int idx2[] = { 1,-1,0,0 };

struct Robot
{
	Pair front; //선체
	Pair rear; //후체
	int time;
	int dir; // 0 가로 , 1 세로

	Robot() {}

	Robot(Pair front, Pair rear, int time, int dir)
	{
		this->front = front;
		this->rear = rear;
		this->time = time;
		this->dir = dir;
	}
};

vector<vector<int>>map;
bool visited[101][101][2];
int N;

bool check(Pair front, Pair rear)
{
	if (front.first < 0 || front.first >= N || front.second < 0 || front.second >= N)
		return true;

	if (rear.first < 0 || rear.first >= N || rear.second < 0 || rear.second >= N)
		return true;

	if (map[front.first][front.second] || map[rear.first][rear.second])
		return true;

	return false;
}

int bfs(Robot start)
{
	queue<Robot>q;
	q.push(start);
	visited[start.front.first][start.front.second][0] = true;

	while (q.empty() != true)
	{
		Robot robot = q.front();
		q.pop();

		if ((robot.front.first == N - 1 && robot.front.second == N - 1) || (robot.rear.first == N - 1 && robot.rear.second == N - 1))
		{
			return robot.time;
		}

		//4방향 이동
		for (int i = 0; i < 4; i++)
		{
			Robot next_robot = Robot(
				Pair(robot.front.first + idx1[i], robot.front.second + idx2[i]),
				Pair(robot.rear.first + idx1[i], robot.rear.second + idx2[i]),
				robot.time + 1, robot.dir
			);

			if (check(next_robot.front, next_robot.rear))
				continue;

			if (!visited[next_robot.front.first][next_robot.front.second][next_robot.dir])
			{
				visited[next_robot.front.first][next_robot.front.second][next_robot.dir] = true;
				q.push(next_robot);
			}
		}

		//가로방향회전
		if (robot.dir == 0)
		{
			//UP
			if (!check(Pair(robot.front.first - 1, robot.front.second), Pair(robot.rear.first - 1, robot.rear.second)))
			{
				if (!visited[robot.front.first - 1][robot.front.second][!robot.dir])
				{
					Robot rotated_robot = Robot(
						Pair(robot.front.first - 1, robot.front.second),
						robot.front,
						robot.time + 1, !robot.dir
					);
					visited[robot.front.first - 1][robot.front.second][!robot.dir] = true;
					q.push(rotated_robot);
				}
				if (!visited[robot.rear.first - 1][robot.rear.second][!robot.dir])
				{
					Robot rotated_robot = Robot(
						Pair(robot.rear.first - 1, robot.rear.second),
						robot.rear,
						robot.time + 1, !robot.dir
					);
					visited[robot.rear.first - 1][robot.rear.second][!robot.dir] = true;
					q.push(rotated_robot);
				}
			}
			//DOWN
			if (!check(Pair(robot.front.first + 1, robot.front.second), Pair(robot.rear.first + 1, robot.rear.second)))
			{
				if (!visited[robot.front.first][robot.front.second][!robot.dir])
				{
					Robot rotated_robot = Robot(
						robot.front,
						Pair(robot.front.first + 1, robot.front.second),
						robot.time + 1, !robot.dir
					);
					visited[robot.front.first][robot.front.second][!robot.dir] = true;
					q.push(rotated_robot);
				}
				if (!visited[robot.rear.first][robot.rear.second][!robot.dir])
				{
					Robot rotated_robot = Robot(
						robot.rear,
						Pair(robot.rear.first + 1, robot.rear.second),
						robot.time + 1, !robot.dir
					);
					visited[robot.rear.first][robot.rear.second][!robot.dir] = true;
					q.push(rotated_robot);
				}
			}
		}
		// 세로방향회전
		else
		{
			//LEFT
			if (!check(Pair(robot.front.first, robot.front.second - 1), Pair(robot.rear.first, robot.rear.second - 1)))
			{
				if (!visited[robot.front.first][robot.front.second - 1][!robot.dir])
				{
					Robot rotated_robot = Robot(
						Pair(robot.front.first, robot.front.second - 1),
						robot.front,
						robot.time + 1, !robot.dir
					);
					visited[robot.front.first][robot.front.second - 1][!robot.dir] = true;
					q.push(rotated_robot);
				}
				if (!visited[robot.rear.first][robot.rear.second - 1][!robot.dir])
				{
					Robot rotated_robot = Robot(
						Pair(robot.rear.first, robot.rear.second - 1),
						robot.rear,
						robot.time + 1, !robot.dir
					);
					visited[robot.rear.first][robot.rear.second - 1][!robot.dir] = true;
					q.push(rotated_robot);
				}
			}
			//RIGHT
			if (!check(Pair(robot.front.first, robot.front.second + 1), Pair(robot.rear.first, robot.rear.second + 1)))
			{
				if (!visited[robot.front.first][robot.front.second][!robot.dir])
				{
					Robot rotated_robot = Robot(
						robot.front,
						Pair(robot.front.first, robot.front.second + 1),
						robot.time + 1, !robot.dir
					);
					visited[robot.front.first][robot.front.second][!robot.dir] = true;
					q.push(rotated_robot);
				}
				if (!visited[robot.rear.first][robot.rear.second][!robot.dir])
				{
					Robot rotated_robot = Robot(
						robot.rear,
						Pair(robot.rear.first, robot.rear.second + 1),
						robot.time + 1, !robot.dir
					);
					visited[robot.rear.first][robot.rear.second][!robot.dir] = true;
					q.push(rotated_robot);
				}
			}
		}
	}
}

int solution(vector<vector<int>> board) {
	map = board;
	N = board.size();
	int answer = bfs(Robot(Pair(0, 0), Pair(0, 1), 0, 0));
	return answer;
}

int main()
{


	return 0;
}