#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,-1,0,1 };

int board[101][101];

struct DragonCurve
{
	stack<int>way;
	Pair pos;
	int generation;
};

DragonCurve dragon[20];
int n;

int getNextWay(int way)
{
	switch (way)
	{
	case 0: return 1;
	case 1: return 2;
	case 2: return 3;
	case 3: return 0;
	}
}

void setDragonCurve()
{
	for (int i = 0; i < n; i++)
	{
		Pair next = Pair(dragon[i].pos.first + dy[dragon[i].way.top()], dragon[i].pos.second + dx[dragon[i].way.top()]);
		board[next.first][next.second] = 1;
		dragon[i].pos.first = next.first;
		dragon[i].pos.second = next.second;

		for (int j = 0; j < dragon[i].generation; j++)
		{
			stack<int>temp = dragon[i].way;

			while (dragon[i].way.empty() != true)
			{
				int nextWay = getNextWay(dragon[i].way.top());
				Pair next = Pair(dragon[i].pos.first + dy[nextWay], dragon[i].pos.second + dx[nextWay]);
				board[next.first][next.second] = 1;
				dragon[i].pos.first = next.first;
				dragon[i].pos.second = next.second;
				temp.push(nextWay);
				dragon[i].way.pop();
			}
			dragon[i].way = temp;
		}
	}
}

bool check(Pair pos)
{
	bool ret = true;
	Pair pos1 = pos;
	Pair pos2 = Pair(pos.first + 0, pos.second + 1);
	Pair pos3 = Pair(pos.first + 1, pos.second);
	Pair pos4 = Pair(pos.first + 1, pos.second + 1);

	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0: if(board[pos1.first][pos1.second] == 0) return ret = false;
			break;
		case 1: if (board[pos2.first][pos2.second] == 0) return ret = false;
			break;
		case 2:if (board[pos3.first][pos3.second] == 0) return ret = false;
			break;
		case 3:if (board[pos4.first][pos4.second] == 0) return ret = false;
			break;
		}
	}
	return ret;
}

int getCntOfRange()
{
	int cnt = 0;

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (check(Pair(i, j))) cnt++;
		}
	}
	return cnt;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		scanf("%d %d %d %d", &x, &y, &d, &g);
		dragon[i].pos = Pair(y, x);
		board[y][x] = 1;
		dragon[i].way.push(d);
		dragon[i].generation = g;
	}

	setDragonCurve();
	cout << getCntOfRange() << endl;
	return 0;
}