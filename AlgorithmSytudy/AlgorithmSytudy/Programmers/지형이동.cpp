#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;
typedef pair<pair<int, int>, int> MST_Pair;

const int idx1[] = { 0,0,1,-1 };
const int idx2[] = { 1,-1,0,0 };

vector<vector<int>>range_of_land;
vector<vector<int>>visited;
vector<MST_Pair>edges;
int answer;
int parent[100001];

void bfs(vector<vector<int>>land, Pair start, int number, int height)
{
	queue<Pair>q;
	q.push(start);
	visited[start.first][start.second] = number;

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Pair next = Pair(pos.first + idx1[i], pos.second + idx2[i]);

			if (next.first < 0 || next.first >= visited.size() || next.second < 0 || next.second >= visited.size())
				continue;

			if (visited[next.first][next.second] == 0 && abs(land[pos.first][pos.second] - land[next.first][next.second]) <= height)
			{
				q.push(next);
				visited[next.first][next.second] = number;
			}
		}
	}
}

void setRange(vector<vector<int>> land, int height)
{
	for (int i = 0, cnt = 0; i < land.size(); i++)
	{
		for (int j = 0; j < land[i].size(); j++)
		{
			if (visited[i][j] == 0)
				bfs(land, Pair(i, j), ++cnt, height);
		}
	}
}

bool comp(MST_Pair p1, MST_Pair p2) {
	return p1.second < p2.second ? true : false;
}

int getParent(int idx)
{
	if (parent[idx] == idx) return idx;
	return getParent(parent[idx]);
}

void merge(int v1, int v2)
{
	if (v1 < v2) {
		parent[v2] = v1;
	}
	else {
		parent[v1] = v2;
	}
}

void setMST(vector<vector<int>> land)
{
	for (int i = 0; i < visited.size(); i++)
	{
		for (int j = 0; j < visited[i].size(); j++)
		{
			Pair pos = Pair(i, j);

			for (int k = 0; k < 4; k++)
			{
				Pair next = Pair(pos.first + idx1[k], pos.second + idx2[k]);

				if (next.first < 0 || next.first >= visited.size() || next.second < 0 || next.second >= visited.size())
					continue;
				
				if (visited[pos.first][pos.second] != visited[next.first][next.second]) {
					edges.push_back(MST_Pair(Pair(visited[pos.first][pos.second], visited[next.first][next.second]),
						abs(land[pos.first][pos.second] - land[next.first][next.second])));
				}
			}
		}
	}

	sort(edges.begin(), edges.end(), comp);

	for (auto edge : edges)
	{
		int v1 = edge.first.first;
		int v2 = edge.first.second;
		int weight = edge.second;

		if (getParent(v1) != getParent(v2))
		{
			merge(getParent(v1), getParent(v2));
			answer += weight;
		}
	}
}

int solution(vector<vector<int>> land, int height) {

	for (int i = 1; i <= 100000; i++) parent[i] = i;

	range_of_land = vector<vector<int>>(land.size(), vector<int>(land.size()));
	visited = range_of_land;
	setRange(land, height);
	setMST(land);
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution({ {10,11,10,11},{2,21,20,10},{1,20,21,11},{2,1,2,1} }, 1);
	return 0;
}