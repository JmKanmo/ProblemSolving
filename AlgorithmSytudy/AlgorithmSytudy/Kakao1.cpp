#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string getBinaryNumber(int n, int size)
{
	stack<int>s;
	string binaryNumber = "";

	while (n != 0)
	{
		s.push(n % 2);
		n /= 2;
	}

	while (s.size() < size) {
		s.push(0);
	}

	while (s.empty() != true) {
		binaryNumber += to_string(s.top());
		s.pop();
	}

	return binaryNumber;
}

vector<vector<string>> makeMap(int n, vector<int>arr)
{
	vector<vector<string>>map = vector<vector<string>>(n, vector<string>(n));

	for (int i = 0; i < arr.size(); i++)
	{
		string binNumber = getBinaryNumber(arr[i], n);

		for (int j = 0; j < binNumber.length(); j++)
			map[i][j] = binNumber[j] == '0' ? " " : "#";
	}
	return map;
}

vector<vector<string>> mergeMap(int n, vector<vector<string>>map1, vector<vector<string>>map2)
{
	vector<vector<string>>map = vector<vector<string>>(n, vector<string>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map1[i][j] == "#" || map2[i][j] == "#") map[i][j] = "#";
			else map[i][j] = " ";
		}
	}
	return map;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {

	vector<vector<string>>map = mergeMap(n, makeMap(n, arr1), makeMap(n, arr2));
	vector<string> answer;

	for (int i = 0; i < n; i++) {
		string str = "";
		for (int j = 0; j < n; j++) {
			str += map[i][j];
		}
		answer.push_back(str);
	}
	return answer;
}

int main()
{
	solution(5, { 9, 20, 28, 18, 11 }, { 30, 1, 21, 17, 28 });
	return 0;
}