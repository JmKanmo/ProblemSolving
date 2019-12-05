#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	string str;
	int N;
	string target_str = "";
	double target_N = 0;
	
	cin >> str;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string temp_str;
		int temp_N;
		int s_pos = 0;

		cin >> temp_str >> temp_N;

		for (int j = 0; j < temp_str.length(); j++)
		{
			if (temp_str[j] == str[s_pos])
				s_pos++;
		}

		if (s_pos == str.length())
		{
			if (target_N < (double)temp_N / abs((int)str.length() - (int)temp_str.length()))
			{
				target_N = (double)temp_N / abs((int)str.length() - (int)temp_str.length());
				target_str = temp_str;
			}
		}
	}
	
	if (target_str == "") cout << "No Jam" << endl;
	else cout << target_str << endl;
	return 0;
}