#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int RLE(string s, int len)
{
	if (len == s.length())
		return s.length();

	string prev_str = "";
	string parsed[1001];

	int parsed_idx = 0;
	int sub_pos = 0;
	int cnt = 1;

	for (sub_pos = 0; sub_pos < len; sub_pos++) prev_str += s[sub_pos];
	parsed[parsed_idx] = prev_str;

	while (true)
	{
		if (sub_pos + len > s.length())
			break;

		string next_str = "";

		for (int i = 0; i < len; i++) next_str += s[sub_pos++];

		if (prev_str == next_str)
		{
			cnt++;
			parsed[parsed_idx] = to_string(cnt) + prev_str;
		}
		else
		{
			cnt = 1;
			parsed[++parsed_idx] = next_str;
			prev_str = next_str;
		}
	}

	string final_str = "";

	for (int i = sub_pos; i < s.length(); i++) final_str += s[sub_pos++];

	if (final_str != "")
		parsed[++parsed_idx] = final_str;

	string ret = "";

	for (int i = 0; i <= parsed_idx; i++)
		ret += parsed[i];

	return ret.length();
}

int solution(string s) {
	int answer = 2e9;

	for (int i = 1; i <= s.length(); i++)
		answer = min(answer, RLE(s, i));

	return answer;
}
