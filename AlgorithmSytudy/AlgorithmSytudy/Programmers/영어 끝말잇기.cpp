#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	map<string, int>hash_map;
	vector<int>counter(n + 1);
	int turn = 1;
	bool flag = true;
	string prev_str = "";

	for (int i = 0; i < words.size(); i++)
	{
		counter[turn]++;
		
		if (i > 0 && words[i][0] != prev_str[prev_str.length() - 1])
		{
			flag = false;
			answer.push_back(turn);
			answer.push_back(counter[turn]);
			break;
		}

		if (hash_map[words[i]] != 0) {
			flag = false;
			answer.push_back(turn);
			answer.push_back(counter[turn]);
			break;
		}

		hash_map[words[i]] = 1;
		turn += 1;
		if (turn > n) turn = 1;
		prev_str = words[i];
	}

	if (flag) {
		answer.push_back(0);
		answer.push_back(0);
	}
	return answer;
}

int main()
{
	solution(2, { "hello", "one", "even", "never", "now", "world", "draw" });

}