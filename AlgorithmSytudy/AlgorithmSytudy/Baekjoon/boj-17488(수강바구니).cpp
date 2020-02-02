#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int N, M;
vector<map<int,int>>students;
vector<int>ranges;
vector<vector<int>> subjects;

void init()
{
	cin >> N >> M;
	students = vector<map<int, int>>(N + 1);
	subjects = vector<vector<int>>(M + 1);
	ranges = vector<int>(M + 1);

	for (int i = 1; i <= M; i++) {
		int val;
		cin >> val;
		ranges[i] = val;
	}

	for (int i = 1; i <= 2; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			while (true)
			{
				int val;
				cin >> val;
				if (val == -1)break;
				subjects[val].push_back(j);
			}
		}
		
		for (int k = 1; k <= M; k++)
		{
			if (subjects[k].size() <= ranges[k])
			{
				for (auto elem : subjects[k])
				{
					students[elem][k] = 1;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	init();

	for (int i = 1; i <= N; i++)
	{
		if (students[i].size() == 0) {
			cout << "¸ÁÇß¾î¿ä" << endl;
		}
		else {
			for (auto elem : students[i])
			{
				cout << elem.first << " ";
			}
			cout << endl;
		}
	}
	
	return 0;
}