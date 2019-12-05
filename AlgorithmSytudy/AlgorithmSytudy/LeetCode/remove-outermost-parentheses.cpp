#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

typedef pair<char, int> Pair;

string removeOuterParentheses(string S) {
	string ret = "";
	vector<Pair>v;
	stack<Pair>st;

	int elem = 0;

	for (int i = 0; i < S.length(); i++)
	{
		char ch = S[i];

		if (ch == '(')
		{
			st.push(Pair(ch, st.empty() ? 1 : st.top().second + 1));
			v.push_back(Pair(ch, st.top().second));
		}
		else
		{
			v.push_back(Pair(ch, st.top().second));
			st.pop();
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].second > 1)
		{
			ret += v[i].first;
		}
	}
	return ret;
}

int main()
{
	removeOuterParentheses("(()())(())(()(()))");

	return 0;
}