#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(string& S) {
	// write your code in C++14 (g++ 6.2.0)
	int left = 0, right = S.length() - 1;

	while (left <= right)
	{
		if (S[left] == '?' && S[right] == '?') {
			S[left] = 'a', S[right] = 'a';
		}
		else if (S[left] == '?' || S[right] == '?') {
			if (S[left] == '?' && S[right] != '?') {
				S[left] = S[right];
			}
			else {
				S[right] = S[left];
			}
		}
		left++;
		right--;
	}


	left = 0, right = S.length() - 1;
	
	while (left <= right)
	{
		if (S[left] != S[right]) {
			S = "NO";
			break;
		}
		left++;
		right--;
	}

	return S;
}

int main()
{
	string s = "?a?";
	solution(s);
	return 0;
}