#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int N, M;
int answer;
map<string, int>hash_map;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		hash_map[str] = 1;
	}

	for (int i = 1; i <= M; i++) {
		string str;
		cin >> str;
		if (hash_map.count(str) != 0)answer++;
	}
	cout << answer << endl;
	return 0;
}