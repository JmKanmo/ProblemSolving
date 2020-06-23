#include <iostream>
#include <string>
#include <vector>

using namespace std;

char moveAlpha(char ch, int n)
{
	if (isupper(ch) && (ch+n) > 'Z') {
		ch += n;
		int diff = ch - 'Z';
		ch = 'A';
		ch += diff - 1;
	}
	else if (islower(ch) && (ch+n) > 'z') {
		ch += n;
		int diff = ch - 'z';
		ch = 'a';
		ch += diff - 1;
	}
	else {
		ch += n;
	}
	return ch;
}

string solution(string s, int n) {
	string answer = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (isalpha(s[i])) {
			char ch = moveAlpha(s[i], n);
			s.erase(i, 1);
			s.insert(s.begin() + i, ch);
		}
	}
	return answer = s;
}

int main()
{	
	solution("AB", 1);
	return 0;
}