#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int answer;
vector<string>voca;

bool checkVocaSet(string vocaSet)
{
	bool ret = false;
	vector<int>checked(26);

	for (int i = 0; i < vocaSet.size(); i++) {
		checked[vocaSet[i] - 'a'] = 1;
	}

	for (int i = 0; i < 26; i++) {
		if (!checked[i]) return false;
	}
	return true;
}

void dfs(int idx, int cnt, int Limit, string vocaSet)
{
	if (cnt >= Limit)
	{
		if (checkVocaSet(vocaSet)) answer++;
		return;
	}

	for (int i = idx + 1; i < voca.size(); i++) {
		string temp = vocaSet;
		dfs(i, cnt + 1, Limit, temp + voca[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		cin >> N;
		answer = 0;
		voca.clear();

		for (int i = 1; i <= N; i++)
		{
			string str;
			cin >> str;
			voca.push_back(str);
		}

		for (int i = 1; i <= N; i++) {
			dfs(-1, 0, i, "");
		}

		cout << "#" << t << " " << answer << endl;
	}
	return 0;
}