#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

int N, L, K;
int grade;
vector<Pair>difficulties;

bool comp(Pair p1, Pair p2)
{
	if (p1.second < p2.second) {
		return true;
	}
	else{
		if (p1.second == p2.second) {
			return p1.first > p1.first ? true : false;
		}
		else {
			return false;
		}
	}
}

void init()
{
	cin >> N >> L >> K;

	for (int i = 1, cnt = 0; i <= N; i++)
	{
		int easy, hard;
		cin >> easy >> hard;
		difficulties.push_back(Pair(easy, hard));
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	init();
	sort(difficulties.begin(), difficulties.end(), comp);

	int cnt = 0;

	for (auto elem : difficulties)
	{
		if (L >= elem.second)
		{
			if (cnt + 1 > K) continue;
			grade += 140;
			cnt++;
			continue;
		}
		if (L >= elem.first) {
			if (cnt + 1 > K) continue;
			cnt++;
			grade += 100;
		}
	}
	cout << grade << endl;
	return 0;
}
