#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int test;
	cin >> test;

	for (int t = 0; t < test; t++)
	{
		string str = "", answer = "";
		map<char, int>hash_map;

		cin >> str;
		for (int i = 0; i < str.length(); i++) hash_map[str[i]]++;

		int min_1 = hash_map['L'] < hash_map['R'] ? hash_map['L'] : hash_map['R'];
		int min_2 = hash_map['U'] < hash_map['D'] ? hash_map['U'] : hash_map['D'];

		if (min_1 == 0 && min_2 == 0) {
			cout << 0 << "\n";
		}
		else
		{
			if (min_1 == 0) min_2 = 1;
			else if (min_2 == 0) min_1 = 1;

			for (int i = 0; i < min_1; i++) answer += "L";
			for (int i = 0; i < min_2; i++) answer += "U";
			for (int i = 0; i < min_1; i++) answer += "R";
			for (int i = 0; i < min_2; i++) answer += "D";
			cout << answer.length() << "\n";
			cout << answer << "\n";
		}
	}
	return 0;
}