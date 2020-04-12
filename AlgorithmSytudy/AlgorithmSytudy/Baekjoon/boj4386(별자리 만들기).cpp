#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<double, pair<int, int>>Pair;

int N;
pair<double, double> star[101];
int parent[101];
vector<Pair>edges;
double answer;

void init()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		double a, b;
		cin >> a >> b;
		star[i].first = a;
		star[i].second = b;
		parent[i] = i;
	}
}

double getDistance(pair<double, double>p1, pair<double, double>p2)
{
	return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
}

void setEdges()
{
	for (int i = 1; i < N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			double dist = getDistance(star[i], star[j]);
			edges.push_back(Pair(dist, make_pair(i, j)));
			edges.push_back(Pair(dist, make_pair(j, i)));
		}
	}
	sort(edges.begin(), edges.end());
}

int getParent(int idx) {
	if (parent[idx] == idx) return idx;
	else return getParent(parent[idx]);
}

void setMST()
{
	for (auto elem : edges)
	{
		int p1 = getParent(elem.second.first);
		int p2 = getParent(elem.second.second);

		if (p1 != p2)
		{
			answer += elem.first;
			parent[p1] = p2;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();
	setEdges();
	setMST();
	printf("%.2f\n", answer);
	return 0;
}