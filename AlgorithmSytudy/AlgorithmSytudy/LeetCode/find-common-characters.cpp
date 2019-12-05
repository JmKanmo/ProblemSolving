#include <iostream>
#include <vector>
#include <string>
#include <algorithm>]

using namespace std;

vector<string> commonChars(vector<string>& A) 
{
	vector<string>ret;
	
	string temp = A[0];

	for (int i = 0; i < temp.length(); i++)
	{
		string str = temp.substr(i, 1);
		bool flag = true;
		int cnt = 1;

		for (int j = 1; j < A.size(); j++)
		{
			if (A[j].find(str) > 100) {
				flag = false;
				break;
			}
			cnt++;
		}

		if (cnt == A.size()) 
		{
			for (int j = 1; j < A.size(); j++) 
			{
				A[j].erase(A[j].find(str), 1);
			}
		}

		if (flag) {
			ret.push_back(str);
		}
	}
	return ret;
}

int main()
{
	vector<string>v = { "cool","lock","cook" };
	vector<string>ret = commonChars(v);

	return 0;
}