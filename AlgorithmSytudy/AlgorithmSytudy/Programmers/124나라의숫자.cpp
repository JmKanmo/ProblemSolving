#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getN(int n, int v)
{
	if (n == 0)
	{
		return 4;
	}
	else if (1 <= n && n <= v)
	{
		return 1;
	}
	else if (v + 1 <= n && n <= v * 2)
	{
		return 2;
	}
	else if ((v * 2) + 1 <= n && n < v * 3)
	{
		return 4;
	}
}

string solution(int n) {
	string answer = "";
	long long div = 3;

	while (n > 0)
	{
		answer += to_string(getN(n % div, div / 3));
		n -= div;
		div *= 3;
	}
	reverse(answer.begin(), answer.end());
	return answer;
}

int main()
{
	solution(11);
	return 0;
}