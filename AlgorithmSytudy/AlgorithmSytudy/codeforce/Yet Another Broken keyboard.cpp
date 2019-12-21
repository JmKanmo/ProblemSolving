#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

typedef long long LL;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	string str;
	LL answer = 0;
	map<char, int>hash_map;
	int N, M;

	cin >> N >> M;
	cin >> str;

	for (int i = 0; i < M; i++) {
		char n;
		cin >> n;
		hash_map[n]++;
	}

	for (int i = 0; i < str.length(); i++)
	{
		LL cnt = 0;
		for (int j = i; j < str.length(); j++) {
			if (hash_map[str[j]])cnt++;
			else {
				break;
			}
		}
		i += cnt;
		if (cnt != 0) answer += (LL)(cnt * (cnt + 1)) / 2;
	}
	cout << answer << "\n";

	return 0;
}