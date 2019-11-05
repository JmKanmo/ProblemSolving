#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N, M, V;
vector<int>list;
int linked_map[200001];
vector<int>requests;

void init()
{
	cin >> N >> M >> V;

	for (int i = 0; i < N; i++)
	{
		int C;
		cin >> C;
		list.push_back(C);

		if (i == N - 1)
			linked_map[N - 1] = V - 1;
		else
			linked_map[i] = i + 1;
	}

	for (int i = 0; i < M; i++)
	{
		int K;
		cin >> K;
		requests.push_back(K);
	}
}

void solve()
{
	for (int i = 0; i < requests.size(); i++)
	{
		int len = requests[i];

		if (len < list.size()) {
			cout << list[len] << "\n";
		}
		else {
			len -= (N - 1);
			int cycle = N - V + 1;

			if (len < cycle)
			{
				len--;
				cout << list[V - 1 + len] << "\n";
			}
			else
			{
				len %= cycle;
				len--;
				if (len < 0) cout << list[N - 1] << "\n";
				else cout << list[V - 1 + len] << "\n";
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	init();
	solve();

	return 0;
}