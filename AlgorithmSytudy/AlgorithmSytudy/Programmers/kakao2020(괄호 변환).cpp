#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

pair<string, string> parsedBalancedStr(string p)
{
	int cnt = 0;

	for (int i = 0; i < p.length(); i++)
	{
		char ch = p[i];

		if (ch == '(') {
			cnt++;
		}
		else if (ch == ')') {
			cnt--;
		}
		if (i > 0 && cnt == 0) {
			string left = p.substr(0, i + 1),
				right = p.substr(i + 1, p.length() - (i + 1));
			return make_pair(left, right);
		}
	}
}

bool checkProperStr(string p)
{
	stack<char>st;
	bool ret = false;

	for (int i = 0; i < p.length(); i++)
	{
		if (p[i] == '(') {
			st.push(p[i]);
		}
		else {
			if (st.empty() != true)
				st.pop();
		}
	}
	return st.empty() ? true : false;
}

string reverseStr(string str)
{
	string ret = "";

	for (int i = 0; i < str.length(); i++) {
		ret += (str[i] == '(' ? ')' : '(');
	}
	return ret;
}

string getProperString(string p)
{
	if (p.length() == 0)
		return "";
	else {
		pair<string, string> parsed_str = parsedBalancedStr(p);
		string u = parsed_str.first;
		string v = parsed_str.second;

		if (checkProperStr(u)) {
			return u + getProperString(v);
		}
		else {
			string ret = "(";
			ret += (getProperString(v) + ")");
			u.erase(0, 1);
			u.erase(u.length() - 1, 1);
			u = reverseStr(u);
			ret += u;
			return ret;
		}
	}
}

string solution(string p) {
	return getProperString(p);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cout << solution("(()())()") << endl;
	cout << solution(")(") << endl;
	cout << solution("()))((()") << endl;
	return 0;
}