#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll,ll>Pair;

ll INF = 10000000000000;
vector<Pair>GP[100001];
vector<int>height(100001);
vector<ll>distances_1(100001, INF);
vector<ll>distances_2(100001, INF);
priority_queue<Pair, vector<Pair>, greater<Pair>>pq;

int N, M, D, E;
ll answer = -INF;

void init()
{
	cin >> N >> M >> D >> E;

	for (int i = 1; i <= N; i++) cin >> height[i];

	for (int i = 1; i <= M; i++)
	{
		int a, b, n;
		cin >> a >> b >> n;
		GP[a].push_back(Pair(b, n));
		GP[b].push_back(Pair(a, n));
	}
}

void dijkstra(int start, bool flag)
{
	if (flag)
	{
		pq.push(Pair(0, start));
		distances_1[start] = 0;

		while (pq.empty() != true)
		{
			int cur_pos = pq.top().second;
			ll cur_weight = pq.top().first;
			pq.pop();

			if (cur_weight > distances_1[cur_pos])
				continue;

			for (auto next : GP[cur_pos])
			{
				int next_pos = next.first;
				ll next_weight = cur_weight + next.second;

				if (height[cur_pos] < height[next_pos])
				{
					if (next_weight < distances_1[next_pos])
					{
						distances_1[next_pos] = next_weight;
						pq.push(Pair(next_weight, next_pos));
					}
				}
			}
		}
	}
	else
	{
		pq.push(Pair(0, start));
		distances_2[start] = 0;

		while (pq.empty() != true)
		{
			int cur_pos = pq.top().second;
			ll cur_weight = pq.top().first;
			pq.pop();

			if (cur_weight > distances_2[cur_pos])
				continue;

			for (auto next : GP[cur_pos])
			{
				int next_pos = next.first;
				ll next_weight = cur_weight + next.second;

				if (height[cur_pos] < height[next_pos])
				{
					if (next_weight < distances_2[next_pos])
					{
						distances_2[next_pos] = next_weight;
						pq.push(Pair(next_weight, next_pos));
					}
				}
			}
		}
	}
}

void setKey()
{
	for (int i = 2; i < N; i++)
	{
		ll hp = (distances_1[i] + distances_2[i]) * D;
		if (hp >= INF) continue;
		ll object = height[i] * E;
		answer = max(answer, object - hp);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	init();
	dijkstra(1, true);
	dijkstra(N, false);
	setKey();
	if (answer == -INF) cout << "Impossible" << endl;
	else cout << answer << endl;
	return 0;
}