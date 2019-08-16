#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Desk {
	int number = 0;
	int time = 0;
};

int N, M, K, A, B;

vector<int>customer;
vector<Desk>reception_desk(10);
vector<int> reception_time(10);
vector<Desk>repair_desk(10);
vector<int>repair_time(10);

map<int, int> map_A;
map<int, int> map_B;
int answer;

void solve()
{
	int time = 0;
	int finish = 0;
	queue<int>waiting_q;

	answer = 0;
	map_A.clear();
	map_B.clear();

	while (finish != K)
	{
		for (int i = 1; i <= N; i++)
		{
			if (reception_desk[i].number != 0 && reception_desk[i].time == time) {
				waiting_q.push(reception_desk[i].number);
				reception_desk[i].number = 0;
				reception_desk[i].time = reception_time[i];
			}
		}
		
		for (int i = 1; i <= K; i++)
		{
			if (customer[i] <= time)
			{
				for (int j = 1; j <= N; j++)
				{
					if (reception_desk[j].number == 0)
					{
						if (j == A) map_A.insert(make_pair(i, 0));
						reception_desk[j].number = i;
						reception_desk[j].time += time;
						customer[i] = 987654321;
						break;
					}
				}
			}
		}

		for (int i = 1; i <= M; i++)
		{
			if (repair_desk[i].number != 0 && repair_desk[i].time == time)
			{
				repair_desk[i].number = 0;
				repair_desk[i].time = repair_time[i];
				finish++;
			}
		}

		for (int i = 1; i <= M; i++)
		{
			if (repair_desk[i].number == 0 && waiting_q.empty() != true)
			{
				if (i == B) map_B.insert(make_pair(waiting_q.front(), 0));
				repair_desk[i].number = waiting_q.front();
				waiting_q.pop();
				repair_desk[i].time += time;
			}
		}
		time++;
	}

	for (pair<int, int>pair_A : map_A)
	{
		for (pair<int, int>pair_B : map_B)
		{
			if (pair_A.first == pair_B.first)
				answer += pair_A.first;
		}
	}
	if (answer == 0) answer = -1;
}

int main()
{
	int test;

	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
		customer = vector<int>(K + 1);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &reception_time[i]);
			reception_desk[i].time = reception_time[i];
		}
		for (int i = 1; i <= M; i++) {
			scanf("%d", &repair_time[i]);
			repair_desk[i].time = repair_time[i];
		}
		for (int i = 1; i <= K; i++) scanf("%d", &customer[i]);
		solve();
		printf("#%d %d\n", t, answer);	
	}
	return 0;
}