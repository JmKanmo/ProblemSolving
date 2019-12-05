#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

map<char, int>hash_map;

string get_beautiful(string str)
{
	string ret = "";
	hash_map['a'] = 1;
	hash_map['b'] = 1;
	hash_map['c'] = 1;

	for (int i = 0; i < str.length(); i++)
	{
		char front = 0, rear = 0;

		if (str[i] == '?') {
			if (i > 0 && str[i - 1]!='?') {
				front = str[i-1];
			}
			if (i < str.length() - 1 && str[i + 1] != '?') {
				rear = str[i + 1];
			}
			
			for (auto elem : hash_map)
			{
				if (elem.first != front && elem.first != rear) {
					ret.push_back(elem.first);
					str[i] = elem.first;
					break;
				}
			}
		}
		else {
			ret.push_back(str[i]);
		}
	}
	return ret;
}

bool equal_check(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '?') continue;
		if (i>0 && str[i] == str[i-1]) {
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (equal_check(str)) {
			cout << -1 << endl;
		}
		else {
			cout << get_beautiful(str) << endl;
		}
	}

	return 0;
}