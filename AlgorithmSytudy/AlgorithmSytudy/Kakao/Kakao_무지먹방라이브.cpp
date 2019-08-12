#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

vector<Pair>sorted_arr;
map<int, int>m;
queue<int>q;

bool comp(const Pair& p1, const Pair& p2) { return p1.second < p2.second; }

void init(vector<int>food_times)
{
	int cnt = 1;
	for (int i = 0; i < food_times.size(); i++) sorted_arr.push_back(Pair(cnt++, food_times[i]));
	for (int i = 0; i < sorted_arr.size(); i++) m.insert(Pair(sorted_arr[i].first, 0));
	sort(sorted_arr.begin(), sorted_arr.end(), comp);
}

bool solve(long long& k)
{
	bool ret = true;

	for (int i = 0; i < sorted_arr.size(); i++)
	{
		if (i == 0)
		{
			long long cnt = (long long)(sorted_arr[i].second * (int)sorted_arr.size());
			k -= cnt;
			q.push(sorted_arr[i].first);
		}
		else
		{
			int diff = sorted_arr[i].second - sorted_arr[i - 1].second;
			if (diff == 0) {
				q.push(sorted_arr[i].first);
				continue;
			}
			else {
				long long cnt = (long long)(diff * ((int)sorted_arr.size() - i));
				if (k < cnt) {
					int len = sorted_arr.size() - i;
					k /= len;
					ret = false;
					break;
				}
				else {
					q.push(sorted_arr[i].first);
					k -= cnt;
				}
			}
		}
	}
	return ret;
}

int solution(vector<int> food_times, long long k) {

	int answer = 0;
	init(food_times);

	if (solve(k)) {
		answer = -1;
	}
	else
	{
		while (q.empty() != true)
		{
			m.erase(q.front());
			q.pop();
		}

		queue<int>temp_q;
		for (auto elem : m) temp_q.push(elem.first);
		
		for (int i = 0; i <= k; i++)
		{
			answer = temp_q.front();
			temp_q.push(temp_q.front());
			temp_q.pop();
		}
	}
	return answer;
}

int main()
{
	solution({ 3,5,1,6,5,3 }, 20);

	return 0;
}