#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, char> Pair;

int A, B, N;
priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

void solve()
{
	cin >> A >> B >> N;
	
	int MAX_B = 0, MAX_R = 0;

	for (int i = 1; i <= N; i++)
	{
		int t, m;
		char c;
		cin >> t >> c >> m;

		if (c == 'B')
		{
			t = max(MAX_B, t); // MAX_B = max(MAX_B,t); 이렇게하면 34%에서틀립니다.
			for (int pos = t, j = 0; j < m; j++, pos += A) pq.push(Pair(pos, c));
			MAX_B = t + (m * A);
		}
		else
		{
			t = max(MAX_R, t);// MAX_R = max(MAX_R,t); 이렇게하면 34%에서틀립니다.
			for (int pos = t, j = 0; j < m; j++, pos += B) pq.push(Pair(pos, c));
			MAX_R = t + (m * B);
		}
	}

	vector<int>answer_b, answer_r;
	
	for (int i = 1; pq.empty() != true; i++) {
		Pair os = pq.top();
		pq.pop();

		if (os.second == 'B') {
			answer_b.push_back(i);
		}
		else {
			answer_r.push_back(i);
		}
	}

	cout << answer_b.size() << "\n";
	for (auto e : answer_b) cout << e << " ";
	cout << "\n";
	cout << answer_r.size() << "\n";
	for (auto e : answer_r) cout << e << " ";
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	solve();
	return 0;
}