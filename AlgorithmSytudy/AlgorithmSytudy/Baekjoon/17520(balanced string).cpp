#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	long long  N;
	long long a = 1;

	cin >> N;

	for (int i = 1; i <= N; i+=2)
	{
		if (i + 1 == N || i == N) break;
		a *= 2;
		a %= 16769023;
	}
	cout << (a*2)% 16769023 << endl;
	return 0;
}