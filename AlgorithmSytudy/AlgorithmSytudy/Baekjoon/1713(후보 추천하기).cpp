#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct State
{
	int choice;
	int date;

	State() {}
	State(int choice, int date) {
		this->choice = choice;
		this->date = date;
	}
};

int N, M;
vector<int>v;
map<int, State>students;
set<int>pictures;

void init()
{
	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		int val;
		cin >> val;
		v.push_back(val);
	}
}

int getRemoved()
{
	State removed;
	int removed_idx;
	int idx = 0;

	for (auto elem : students)
	{
		State st = elem.second;

		if (idx == 0)
		{
			removed = State(st.choice, st.date);
			removed_idx = elem.first;
		}
		else
		{
			if (removed.choice > st.choice) {
				removed = st;
				removed_idx = elem.first;
			}
			else if (removed.choice == st.choice) {
				if (removed.date > st.date) {
					removed = st;
					removed_idx = elem.first;
				}
			}
		}
		idx++;
	}
	return removed_idx;
}

void solve()
{
	for (int i = 0, j = 1; i < v.size(); i++, j++)
	{
		if (pictures.size() == N) {
			if (students.count(v[i]) == 0) {
				int removed_idx = getRemoved();
				students.erase(removed_idx);
				pictures.erase(removed_idx);
			}
		}
		pictures.insert(v[i]);
		if (students.count(v[i]) == 0) {
			students[v[i]] = State(1, j);
		}
		else {
			students[v[i]].choice++;
		}
	}
	for (auto elem : pictures) {
		cout << elem << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	init();
	solve();
	return 0;
}