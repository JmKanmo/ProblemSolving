#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(string s)
{
	int answer = 0;
	int length = s.length();

	for (int i = 0; i < s.length() - 1; i++)
	{
		if((length-i+1<=answer)) return answer;

		for (int j = s.length() - 1; j > i; j--)
		{
			int left = i;
			int right = j;
			int sub_len = right - left + 1;

			if (sub_len <= answer) break;

			while (left < right && s[left] == s[right])
			{ 
				left++;
				right--;
			}
			
			if (left >= right) {
				answer = max(answer, sub_len);
			}
		}
	}

	return answer;
}

int main()
{
	int n = solution("abcd");

	return 0;
}