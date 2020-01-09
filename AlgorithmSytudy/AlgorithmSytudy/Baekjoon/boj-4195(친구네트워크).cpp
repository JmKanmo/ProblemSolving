#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int parent[200001];
int cost[200001];

int find(int idx)
{
	if (parent[idx] == idx) return idx;
	else return find(parent[idx]);
}

int merge(int idx1, int idx2)
{
	int p1 = find(idx1), p2 = find(idx2);

	if (p1 != p2)
	{
		parent[p2] = p1;
		cost[p1] += cost[p2];
		cost[p2] = 1;
	}
	return cost[p1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int test;
	cin >> test;

	for (int t = 0; t < test; t++)
	{
		map<string, int>hash_map;
		int N;
		cin >> N;

		for (int i = 0; i <= 2 * N; i++) {
			parent[i] = i;
			cost[i] = 1;
		}

		for (int i = 0, num = 0; i < N; i++) {
			string a, b;
			cin >> a >> b;
			if (hash_map[a] == 0) hash_map[a] = ++num;
			if (hash_map[b] == 0) hash_map[b] = ++num;
			cout << merge(hash_map[a], hash_map[b]) << "\n";
		}
	}

	return 0;
}