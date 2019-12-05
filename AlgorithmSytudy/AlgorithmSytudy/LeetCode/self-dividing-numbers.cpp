#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> selfDividingNumbers(int left, int right) {
	vector<int>answer;

	for (int i = left; i <= right; i++)
	{
		if (i < 10)
			answer.push_back(i);
		else
		{
			int div = 1;
			bool flag = true;
			bool is_zero = false;

			while (i / div != 0)
			{
				int digit = (i / div) % 10;
				if (digit == 0) {
					is_zero = true;
					break;
				}
				if (i % digit != 0)
				{
					flag = false;
					break;
				}
				div *= 10;
			}
			if (flag && is_zero != true) {
				answer.push_back(i);
			}
		}
	}
	return answer;
}

int main()
{
	vector<int>arr = selfDividingNumbers(1, 22);

	return 0;
}