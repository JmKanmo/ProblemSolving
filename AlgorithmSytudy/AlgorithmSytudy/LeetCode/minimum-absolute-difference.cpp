#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
	sort(arr.begin(), arr.end());

	int MIN = 2e9;
	vector<vector<int>>ret;
	vector<int>temp;

	for (int i = 0; i < arr.size() - 1; i++)
	{
		if (abs(arr[i] - arr[i + 1]) <= MIN) {
			MIN = abs(arr[i] - arr[i + 1]);
			temp = { arr[i],arr[i + 1] };
		}
	}

	int diff = abs(temp[0] - temp[1]);

	for (int i = 0; i < arr.size() - 1; i++)
	{
		if (abs(arr[i] - arr[i + 1]) == diff) {
			if (arr[i] < arr[i + 1]) {
				ret.push_back({ arr[i], arr[i + 1] });
			}
			else {
				ret.push_back({ arr[i + 1], arr[i] });
			}
		}
	}
	return ret;
}

int main()
{


	return 0;
}