#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int getMaxofPallindrom(string str)
{
	int len_pallindrom = 1;

	if (str.length() == 1) return len_pallindrom;

	for (int i = 0; i < str.length() - 1; i++)
	{
		if (str.length() - i + 1 <= len_pallindrom) return len_pallindrom;

		for (int j = str.length() - 1; j > i; j--)
		{
			int left = i;
			int right = j;
			int len_diff = right - left + 1;

			if (len_pallindrom >= len_diff) break;

			while (left < right && str[left] == str[right])
			{
				left++;
				right--;
			}
			
			if (left >= right)
			{
				len_pallindrom = len_diff;
			}
		}
	}
	return len_pallindrom;
}

int solution(string s)
{
	int answer = 0;
	answer = getMaxofPallindrom(s);

	return answer;
}

int main()
{
	//string str = "hlerewe";
	//str = str.substr(0,3); //substr(A,B) ---> A에서 B-1만큼 자르기

	cout << solution("abacde") << endl;
	return 0;
}//main()