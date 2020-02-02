#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool check_func(string obj) {
	map<char, int>checked;
	bool ret = false;

	for (int i = 0; i < obj.length(); i++) checked[obj[i]]++;

	for (auto elem : checked) {
		if (elem.second > 1) return true;
	}
	return false;
}

int solution(vector<string>& A) {
	int ret = 0;
	map<string, int>hash_map;
	map<string, int>new_map;

	for (int i = 0; i < A.size(); i++) hash_map[A[i]] = 1;

	while (hash_map.size() > 0)
	{
		for (auto elem : hash_map)
		{
			string str = elem.first;

			for (int i = 0; i < A.size(); i++) {
				string concentration = str + A[i];
				if (check_func(concentration)) continue;
				new_map[concentration] = 1;
				ret = max(ret, (int)concentration.length());
			}
		}
		hash_map = new_map;
		new_map.clear();
	}
	return ret;
}

int main()
{
	vector<string>arr = { "co","dil","ity" };
	int ret = solution(arr);

	return 0;
}
