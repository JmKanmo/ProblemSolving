#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

vector<Pair>jewelry;
vector<int>bag;
int N, K;
long long answer;
int jewelry_idx, bag_idx;
priority_queue<int>pq;

bool comp(Pair p1, Pair p2) { return p1.first < p2.first ? true : false; }

void init()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int M, V;
		cin >> M >> V;
		jewelry.push_back(Pair(M, V));
	}	

	for (int i = 0; i < K; i++)
	{
		int C;
		cin >> C;
		bag.push_back(C);
	}

	sort(jewelry.begin(), jewelry.end(), comp);
	sort(bag.begin(), bag.end());
}

void solve()
{
	while (bag_idx < bag.size())
	{
		while (jewelry_idx < jewelry.size() && bag[bag_idx] >= jewelry[jewelry_idx].first)
			pq.push(jewelry[jewelry_idx++].second);

		if (pq.empty() != true)
		{
			answer += pq.top();
			pq.pop();
		}
		bag_idx++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	init();
	solve();
	cout << answer << endl;
	return 0;
}