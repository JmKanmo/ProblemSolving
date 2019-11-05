#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cookie) {
	int answer = -1;

	for (int t = 0; t < cookie.size() - 1; t++)
	{
		for (int i = t, left_sum = 0; i < cookie.size() - 1; i++)
		{
			left_sum += cookie[i];
			int right_sum = 0;

			if (answer != -1 && left_sum <= answer)
				continue;

			for (int j = i + 1; j < cookie.size(); j++)
			{
				right_sum += cookie[j];

				if (left_sum == right_sum) {
					answer = max(answer, left_sum);
				}
			}
		}
	}
	return answer != -1 ? answer : 0;
}

int main()
{
	solution({ 1,1,2,3 });

	return 0;
}