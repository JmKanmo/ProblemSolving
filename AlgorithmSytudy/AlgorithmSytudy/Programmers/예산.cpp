#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getLimitedBudget(vector<int> budgets, int limit)
{
	int ret = 0;

	for (auto elem : budgets)
	{
		if (elem < limit) ret += elem;
		else ret += limit;
	}
	return ret;
}

int solution(vector<int> budgets, int M) {
	int answer = 0;

	sort(budgets.begin(), budgets.end());

	int left = 0, right = budgets[budgets.size() - 1];

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (getLimitedBudget(budgets, mid) <= M) {
			left = mid + 1;
			answer = max(answer, mid);
		}
		else {
			right = mid - 1;
		}
	}
	return answer;
}