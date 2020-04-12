#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int N;
double percent[4];
int visited[30][30];

void init()
{
	cin >> N;
	for (int i = 0; i < 4; i++) cin >> percent[i];
}

double dfs(int curX, int curY, int depth)
{
	if (depth >= N)
		return 1.0;

	visited[curX][curY] = 1;

	double ret = 0.0;

	for (int i = 0; i < 4; i++)
	{
		int nextX = curX + dx[i];
		int nextY = curY + dy[i];

		if (visited[nextX][nextY])
			continue;

		ret += dfs(nextX, nextY, depth + 1) * percent[i] / 100;
	}
	visited[curX][curY] = 0;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();
	printf("%.9f\n", dfs(15, 15, 0));
	return 0;
}