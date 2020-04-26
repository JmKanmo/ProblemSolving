#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

int N, M;
vector<Pair>GP[11];
vector<int>visited(11);
int answer;

void dfs(int idx, int cnt)
{
	answer = max(answer, cnt);

	for (auto elem : GP[idx]) {
		if (!visited[elem.first])
		{
			visited[elem.first] = 1;
			dfs(elem.first, cnt + 1);
			visited[elem.first] = 0;
		}
	}
}

void clear() {
	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
		GP[i].clear();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		cin >> N >> M;
		answer = 0;
		for (int j = 1; j <= M; j++) {
			int x, y;
			cin >> x >> y;
			GP[x].push_back(Pair(y, 1));
			GP[y].push_back(Pair(x, 1));
		}

		if (M == 0) {
			cout << "#" << t << " " << 1 << "\n";
		}
		else {
			for (int i = 1; i <= N; i++) {
				visited[i] = 1;
				dfs(i, 1);
				visited[i] = 0;
			}
			cout << "#" << t << " " << answer << "\n";
		}
		clear();
	}
	return 0;
}