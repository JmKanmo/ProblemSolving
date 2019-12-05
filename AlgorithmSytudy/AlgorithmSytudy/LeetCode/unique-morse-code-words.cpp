#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int uniqueMorseRepresentations(vector<string>& words) {
	vector<string>tatoos = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
	vector<char> alphabets = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	map<char, string>hash_map;
	map<string, int>words_map;

	for (int i = 0; i < alphabets.size(); i++) hash_map[alphabets[i]] = tatoos[i];

	for (int i = 0; i < words.size(); i++)
	{
		string word = words[i];
		string temp = "";

		for (int j = 0; j < word.length(); j++)
		{
			temp += hash_map[word[j]];
		}
		words_map[temp] = 1;
	}
	return words_map.size();
}

int main()
{
	vector<string>words = { "gin","zen","gig","msg" };
	uniqueMorseRepresentations(words);
}