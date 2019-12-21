#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool check_balance(string& str)
{
	stack<char>st;

	for (int i = 0; i < str.length(); i++)
	{
		char ch = str[i];

		switch (ch)
		{
		case '(':
		case '[':
			st.push(ch);
			break;

		case ')':
			if (!st.empty() && st.top() == '(')
			{
				st.pop();
				break;
			}
			else
			{
				return false;
			}

		case ']':
			if (!st.empty() && st.top() == '[')
			{
				st.pop();
				break;
			}
			else
			{
				return false;
			}
		}
	}
	if (st.empty() != true) return false;

	return true;
}

int main()
{
	while (true)
	{
		string str;
		getline(cin, str);
		if (str == ".") 
			break;
		if (check_balance(str)) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}
	return 0;
}