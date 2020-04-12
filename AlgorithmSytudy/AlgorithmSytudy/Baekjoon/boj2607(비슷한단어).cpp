#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<string> vocas;
int answer;

void init()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		vocas.push_back(str);
	}
}

void solve()
{
	string first_str = vocas[0];
	map<char, int> hash_map;

	for (int i = 0; i < first_str.length(); i++) hash_map[first_str[i]] ++;

	for (int i = 1; i < vocas.size(); i++)
	{
		map<char, int> first_map = hash_map;
		map<char, int> temp_map;
		string second_str = vocas[i];
		int diff = first_str.length() - second_str.length();

		if (abs(diff) > 1) continue;

		for (int j = 0; j < second_str.length(); j++) temp_map[second_str[j]]++;

		for (int j = 0; j < first_str.length(); j++)
		{
			if (first_map[first_str[j]] && temp_map[first_str[j]]) {
				first_map[first_str[j]]--;
				temp_map[first_str[j]]--;
			}
		}

		int first_size = 0, temp_size = 0;

		for (auto elem : first_map) {
			if (elem.second > 0) first_size += elem.second;
		}
		for (auto elem : temp_map) {
			if (elem.second > 0) temp_size += elem.second;
		}

		if (first_size == 0 && temp_size == 0 || first_size == 1 && temp_size == 1) answer++;
		if (first_size == 1 && temp_size == 0 || first_size == 0 && temp_size == 1) answer++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();

	if (N == 0) {
		cout << 0 << endl;
	}
	else {
		solve();
		cout << answer << endl;
	}
	return 0;
}