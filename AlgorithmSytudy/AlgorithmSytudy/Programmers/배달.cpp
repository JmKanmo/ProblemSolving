#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

typedef pair<int, int> Pair;

const int INF = 2e9;
priority_queue<Pair, vector<Pair>, greater<Pair>>pq;
vector<int>distances;
vector<Pair>GP[51];

void dijkstra()
{
	pq.push(Pair(0, 1));
	distances[1] = 0;

	while (pq.empty() != true)
	{
		int pos = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		for (auto next : GP[pos])
		{
			int next_pos = next.first;
			int next_cost = cost + next.second;

			if (distances[next_pos] > next_cost)
			{
				distances[next_pos] = next_cost;
				pq.push(Pair(next_cost, next_pos));
			}
		}
	}
}

int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	distances = vector<int>(N + 1, INF);

	for (int i = 0; i < road.size(); i++)
	{
		GP[road[i][0]].push_back(Pair(road[i][1], road[i][2]));
		GP[road[i][1]].push_back(Pair(road[i][0], road[i][2]));
	}

	dijkstra();
	
	for (int i = 1; i <= N; i++)
	{
		if (distances[i] <= K) answer++;
	}

	return answer;
}

int main()
{



	return 0;
}