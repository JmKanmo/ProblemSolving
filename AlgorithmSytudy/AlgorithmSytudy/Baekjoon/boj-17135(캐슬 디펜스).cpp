#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

struct Kill
{
	int idx1 = -1, idx2 = -1, d = -1;
};

int N, M, D;
vector<Pair>enermy;
vector<Pair>hunters;
Kill kills[3];
int answer;

void init()
{
	cin >> N >> M >> D;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int val;
			cin >> val;
			if (val == 1) enermy.push_back(Pair(i, j));
		}
	}
}

void hunting()
{
	vector<Pair>temp_enermy = enermy;
	int hunted_cnt = 0;

	while (true)
	{
		if (temp_enermy.empty())
			break;

		//완탐(각각의 궁수가 사냥할 적)
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < temp_enermy.size(); j++)
			{
				int distance = abs(hunters[i].first - temp_enermy[j].first) + abs(hunters[i].second - temp_enermy[j].second);

				if (distance > 0 && distance <= D)
				{
					if (kills[i].d == -1)
					{
						kills[i].idx1 = temp_enermy[j].first;
						kills[i].idx2 = temp_enermy[j].second;
						kills[i].d = distance;
					}
					else
					{
						if (kills[i].d > distance)
						{
							kills[i].idx1 = temp_enermy[j].first;
							kills[i].idx2 = temp_enermy[j].second;
							kills[i].d = distance;
						}
						else if (kills[i].d == distance)
						{
							if (kills[i].idx2 > temp_enermy[j].second)
							{
								kills[i].idx1 = temp_enermy[j].first;
								kills[i].idx2 = temp_enermy[j].second;
								kills[i].d = distance;
							}
						}
					}
				}
			}
		}

		//공격받은 적 삭제
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < temp_enermy.size(); j++)
			{
				if (kills[i].idx1 == temp_enermy[j].first && kills[i].idx2 == temp_enermy[j].second)
				{
					temp_enermy.erase(temp_enermy.begin() + j);
					hunted_cnt++;
					break;
				}
			}
			kills[i].idx1 = -1, kills[i].idx2 = -1, kills[i].d = -1;
		}

		//적 아래로 한칸씩 이동
		for (int j = 0; j < temp_enermy.size(); j++)
		{
			if (temp_enermy[j].first + 1 >= N) {
				temp_enermy.erase(temp_enermy.begin() + j--);
			}
			else {
				temp_enermy[j].first++;
			}
		}
	}
	answer = max(answer, hunted_cnt);
}

void dfs(int idx, int cnt)
{
	if (cnt == 3)
	{
		hunting();
		return;
	}

	for (int i = idx + 1; i < M; i++)
	{
		hunters.push_back(Pair(N, i));
		dfs(i, cnt + 1);
		hunters.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	init();
	dfs(-1, 0);
	cout << answer << endl;
	return 0;
}