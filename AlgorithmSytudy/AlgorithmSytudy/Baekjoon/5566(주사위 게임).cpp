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

int N, M;

vector<int>pos;
vector<int>order(1001);

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		int val;
		cin >> val;
		order[i] = val;
	}

	for (int i = 1; i <= M; i++)
	{
		int val;
		cin >> val;
		pos.push_back(val);
	}

	int step = 1;

	for (int i = 0, j = 0; i < pos.size(); i++)
	{
		step += pos[i];
		j += 1;
		step += order[step];
		if (step >= N) {
			cout << j << "\n";
			break;
		}
	}

	return 0;
}