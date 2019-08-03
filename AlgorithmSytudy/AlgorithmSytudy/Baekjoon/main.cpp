#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string getLeftStr(int left, int right, string str)
{
	return str.substr(left, right - left + 1);
}

string getRightStr(int left, int right, string str)
{
	string temp = str.substr(left, right - left + 1);
	reverse(temp.begin(), temp.end());
	return temp;
}

int getMaxofPallendrom(string str)
{
	int len_pallendrom = 1;

	if (str.length() == 1) return len_pallendrom;

	for (int i = 0; i < str.length() - 1; i++)
	{
		if (((str.length() - 1) - i + 1) <= len_pallendrom) break;

		for (int j = str.length()-1; j >i; j--)
		{
			if ((j - i + 1) < len_pallendrom) break;

			int mid = (i + j) / 2;
			string left = getLeftStr(i, mid, str);
			string right = getRightStr((i + j + 1) % 2 == 0 ? mid + 1 : mid, j, str);

			if (left == right) {
				int len = (i + j + 1) % 2 == 0 ? left.length() + right.length() : left.length() + right.length() - 1;
				len_pallendrom = max(len_pallendrom, len);
			}
		}
	}
	return len_pallendrom;
}

int solution(string s)
{
	int answer = 0;
	answer = getMaxofPallendrom(s);

	return answer;
}

int main()
{
	//string str = "hlerewe";
	//str = str.substr(0,3); //substr(A,B) ---> A에서 B-1만큼 자르기

	cout << solution("abacde") << endl;
	return 0;
}//main()