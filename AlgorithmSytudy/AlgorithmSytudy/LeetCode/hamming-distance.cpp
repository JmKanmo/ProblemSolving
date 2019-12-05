#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

stack<int> getBinary(int N)
{
	stack<int>binary;

	while (N / 2 != 0)
	{
		binary.push(N % 2);
		N /= 2;
	}

	if (N != 0) binary.push(1);
	else binary.push(0);

	int n = 32 - binary.size();

	for (int i = 0; i < n; i++) binary.push(0);
	return binary;
}

int hammingDistance(int x, int y) {

	stack<int>ret_x = getBinary(x);
	stack<int>ret_y = getBinary(y);
	int answer = 0;

	while (ret_x.empty() != true && ret_y.empty() != true)
	{
		int pos_x = ret_x.top();
		int pos_y = ret_y.top();
		if (pos_x != pos_y) answer++;
		ret_x.pop();
		ret_y.pop();
	}
	return answer;
}

int main()
{
	hammingDistance(0, 1);
	
	cout << endl;
	return 0;
}