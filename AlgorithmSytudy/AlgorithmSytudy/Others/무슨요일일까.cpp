#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string keys[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

int month_days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

void check_LeapYear(int year)
{

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		month_days[1] = 29;
}

string getKeyDays(int year, int month, int day)
{
	int total_days = 0;

	check_LeapYear(year);

	for (int i = 0; i < month - 1; i++)
		total_days += month_days[i];

	total_days += day - 1;
	total_days = (1 + total_days) % 7;
	return keys[total_days];
}

string solution(int a, int b) {
	string answer = "";
	return answer;
}

int main()
{
	int x, y;
	cin >> x >> y;
	cout << getKeyDays(2007, x, y) << endl;

}