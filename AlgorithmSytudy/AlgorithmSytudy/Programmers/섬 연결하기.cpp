#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<pair<int, int>, int> Pair;

vector<Pair>GP;
int parent[100];

bool comp(Pair p1, Pair p2) { return p1.second < p2.second ? true : false; }

int getParent(int idx)
{
	if (parent[idx] == idx)
		return idx;
	else
		return getParent(parent[idx]);
}

void merge(int p1, int p2)
{
	if (p1 < p2)
		parent[p2] = p1;
	else
		parent[p1] = p2;
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;

	for (int i = 0; i < costs.size(); i++) 
		GP.push_back(Pair(make_pair(costs[i][0], costs[i][1]), costs[i][2]));

	sort(GP.begin(), GP.end(), comp);

	for (int i = 0; i < n; i++) parent[i] = i;

	for (auto elem : GP)
	{
		int p1 = getParent(elem.first.first);
		int p2 = getParent(elem.first.second);

		if (p1 != p2) {
			merge(p1, p2);
			answer += elem.second;
		}
	}

	return answer;
}

int main()
{
	solution(4, { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} });

	return 0;
}