#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;
string target;
int answer;

void init()
{
	getline(cin, str);
	getline(cin, target);
}

int solve(int start)
{
	int target_len = target.size();
	int str_len = str.size();
	int cnt = start;
	int ret = 0;

	while (true)
	{
		if (cnt + target_len - 1 < str_len)
		{
			string sub_str = str.substr(cnt, target_len);
			if (target == sub_str)
			{
				ret++;
				cnt += target_len;
			}
			else {
				cnt++;
			}
		}
		else
		{
			break;
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	init();

	for (int i = 0; i < str.size(); i++) {
		answer = max(answer, solve(i));
	}

	cout << answer << endl;
	return 0;
}