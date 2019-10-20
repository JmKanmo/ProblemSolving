#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, string> Pair;

string toLower(string city)
{
	for (int i = 0; i < city.length(); i++) city[i] = tolower(city[i]);
	return city;
}

void cache_Elem_Plus(vector<Pair>&cache) {
	for (int i = 0; i < cache.size(); i++) {
		cache[i] = Pair(cache[i].first + 1, cache[i].second);
	}
}

bool isEqualElem(vector<Pair>&cache, string city, int& answer)
{
	bool ret = false;

	for (int i = 0; i < cache.size(); i++)
	{
		if (cache[i].second == city)
		{
			ret = true;
			cache[i].first = 1;
			break;
		}
	}
	if (ret) answer += 1;
	return ret;
}

void cache_Change(vector<Pair>&cache, string city)
{
	int idx = 0, max = 0;

	for (int i = 0; i < cache.size(); i++)
	{
		if (cache[i].first > max) {
			idx = i;
			max = cache[i].first;
		}
	}

	if (cache.size() > 0) {
		cache[idx].first = 1;
		cache[idx].second = city;
	}
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	vector<Pair>cache;

	for (int i = 0; i < cities.size(); i++)
	{
		string city = toLower(cities[i]);	
		cache_Elem_Plus(cache); //모든원소cnt 1씩증가

		if (cache.size() < cacheSize) {
			if (isEqualElem(cache, city, answer) != true) {
				cache.push_back(Pair(1, city));
				answer += 5;
			}
		}
		else {
			if (isEqualElem(cache, city, answer) != true) {
				cache_Change(cache, city);
				answer += 5;
			}
		}
	}
	return answer;
}

int main()
{
	int n = solution(0, { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul" });

	cout << n << endl;
	return 0;
}