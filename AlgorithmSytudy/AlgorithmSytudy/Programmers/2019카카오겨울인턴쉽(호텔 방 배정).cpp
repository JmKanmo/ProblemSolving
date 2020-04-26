#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long LL;

vector<LL> solution(LL k, vector<LL> room_number)
{
	vector<LL> answer;
	map<LL, LL> hash_map;

	for (int i = 0; i < room_number.size(); i++)
	{
		LL number = room_number[i];

		if (hash_map.count(number) == 0) {
			hash_map[number] = number + 1;
			answer.push_back(number);
		}
		else {
			vector<LL>v;
			while (hash_map.count(number) != 0) {
				v.push_back(number);
				number = hash_map[number];
			}
			answer.push_back(number);
			hash_map[number] = number + 1;
			for (int i = 0; i < v.size(); i++) {
				hash_map[v[i]] = number + 1;
			}
		}
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	solution(10, { 1,3,4,1,3,1 });
	return 0;
}