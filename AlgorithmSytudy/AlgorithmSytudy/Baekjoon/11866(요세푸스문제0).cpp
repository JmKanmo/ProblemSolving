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

	int N, K;
	queue<int>q;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	vector<int>v;

	while (q.empty() != true)
	{
		for (int i = 1; i <= K - 1; i++)
		{
			q.push(q.front());
			q.pop();
		}
		v.push_back(q.front());
		q.pop();
	}

	cout << "<";
	for (int i = 0; i < v.size(); i++) {
		if (i == v.size() - 1) {
			cout << v[i] << ">" << "\n";
		}
		else {
			cout << v[i] << ", ";
		}
	}
	return 0;
}


