#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

int N, M;
map<string, int> hash_map1;
map<int, string>hash_map2;

void init()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		hash_map1[str] = i;
		hash_map2[i] = str;
	}
}

void solve()
{
	for (int i = 1; i <= M; i++) {
		string str;
		cin >> str;

		if (hash_map1.count(str) == 0) {
			int id = stoi(str);
			cout << hash_map2[id] << "\n";
		}
		else {
			cout << hash_map1[str] << "\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	init();
	solve();
	return 0;
}