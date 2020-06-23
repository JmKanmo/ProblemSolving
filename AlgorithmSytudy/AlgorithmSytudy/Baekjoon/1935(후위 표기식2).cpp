#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

int N;
string str;
vector<int>hash_map;
double answer;
stack<double>st;

void init()
{
	cin >> N;
	cin >> str;

	for (int i = 1; i <= N; i++)
	{
		int val;
		cin >> val;
		hash_map.push_back(val);
	}
}

double getExp(char op)
{
	double second = st.top();
	st.pop();
	double first = st.top();
	st.pop();

	switch (op)
	{
	case '*':
		return first * second;
	case '/':
		return first / second;
	case '+':
		return first + second;
	case '-':
		return first - second;
	}
}

void solve()
{
	for (int i = 0; i < str.length(); i++)
	{
		if (isalpha(str[i]))
		{
			st.push(hash_map[str[i] - 'A']);
		}
		else
		{
			st.push(getExp(str[i]));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	init();
	solve();
	printf("%.2f\n", st.top());
	st.pop();
	return 0;
}