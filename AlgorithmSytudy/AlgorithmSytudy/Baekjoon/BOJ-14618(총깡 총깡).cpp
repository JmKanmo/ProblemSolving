#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int, int> Pair;

const int INF = 2e9;
int N, M, K;
int home;
map<int, int>home_A, home_B;
vector<Pair>GP[5001];
vector<int>distances(5001, INF);
priority_queue<Pair, vector<Pair>, greater<Pair>>pq;

void init()
{
	cin >> N >> M;
	cin >> home;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int input;
		cin >> input;
		home_A[input] = 1;
	}

	for (int i = 0; i < K; i++)
	{
		int input;
		cin >> input;
		home_B[input] = 1;
	}

	for (int i = 0; i < M; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		GP[x].push_back(Pair(y, z));
		GP[y].push_back(Pair(x, z));
	}
}

void dijkstra()
{
	pq.push(Pair(0, home));
	distances[home] = 0;

	while (pq.empty() != true)
	{
		int vertex = pq.top().second;
		int weight = pq.top().first;
		pq.pop();

		for (auto next : GP[vertex])
		{
			int next_weight = weight + next.second;

			if (distances[next.first] > next_weight)
			{
				distances[next.first] = next_weight;
				pq.push(Pair(next_weight, next.first));
			}
		}
	}
}

void print_answer()
{
	int res = INF;
	char res2;

	for (auto elem : home_B)
	{
		if (distances[elem.first] < res) {
			res = distances[elem.first];
			res2 = 'B';
		}
	}

	for (auto elem : home_A)
	{
		if (distances[elem.first] <= res) {
			res = distances[elem.first];
			res2 = 'A';
		}
	}

	if (res == INF) {
		cout << -1 << endl;
	}
	else {
		cout << res2 << '\n' << res << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	init();
	dijkstra();
	print_answer();

	return 0;
}