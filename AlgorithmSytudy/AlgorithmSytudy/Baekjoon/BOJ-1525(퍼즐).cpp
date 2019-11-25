#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> Pair;

const int idx1[] = { 0,0,1,-1 };
const int idx2[] = { 1,-1,0,0 };

int input()
{
	int ret = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int n = 0;
			cin >> n;
			n = n == 0 ? 9 : n;
			ret *= 10;
			ret += n;
		}
	}
	return ret;
}

void bfs(int n)
{
	queue<Pair>q;
	map<int, int>hash_map;
	q.push(Pair(n, 0));

	while (q.empty() != true)
	{
		string status = to_string(q.front().first);
		int counter = q.front().second;
		q.pop();

		if (status == "123456789")
		{
			cout << counter << endl;
			return;
		}

		Pair pos = Pair(status.find('9') / 3, status.find('9') % 3);

		for (int i = 0; i < 4; i++)
		{
			Pair next = Pair(pos.first + idx1[i], pos.second + idx2[i]);

			if (next.first < 0 || next.first >= 3 || next.second < 0 || next.second >= 3)
				continue;

			string temp = status;

			swap(temp[(pos.first * 3) + pos.second], temp[(next.first * 3) + next.second]);

			if (hash_map[stoi(temp)] == 0)
			{
				hash_map[stoi(temp)] = 1;
				q.push(Pair(stoi(temp), counter + 1));
			}
		}
	}
	cout << -1 << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	bfs(input());
	return 0;
}
