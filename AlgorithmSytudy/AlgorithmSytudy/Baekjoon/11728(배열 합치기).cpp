#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	multiset<int>hash_set;

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int val;
		cin >> val;
		hash_set.insert(val);
	}
	for (int i = 1; i <= M; i++) {
		int val;
		cin >> val;
		hash_set.insert(val);
	}

	for (auto elem : hash_set) {
		cout << elem << " ";
	}
	cout << "\n";
	return 0;
}