#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int user[1001];
vector<int>followers[1001];
string cards;
int card_size;

void init()
{
	cin >> N;
	getchar();
	getline(cin, cards);
	cards.erase(remove_if(cards.begin(), cards.end(), isspace), cards.end());
	for (int i = 0; i < cards.length(); i++) if (isdigit(cards[i]) == 0) card_size++;
}

void solve()
{
	for (int i = 0, card_idx = 0; card_idx < cards.length(); i++, card_idx++)
	{
		switch (cards[card_idx])
		{
		case 'A':
		{
			vector<int>candy(N);
			queue<int>q;
			q.push(i % N);
			user[i % N]++;

			while (q.empty() != true)
			{
				int pos = q.front();
				q.pop();

				for (auto next : followers[pos])
				{
					if (candy[next] < 1)
					{
						candy[next]++;
						user[next]++;
						q.push(next);
					}
				}
			}
			break;
		}
		case 'J':
		{
			int left = (i % N) - 1 < 0 ? N - 1 : (i % N) - 1;
			int right = (i % N) + 1 >= N ? 0 : (i % N) + 1;
			user[left]++;
			user[right]++;

			vector<int>candy(N);
			queue<int>q;
			q.push(left);
			q.push(right);

			while (q.empty() != true)
			{
				int pos = q.front();
				q.pop();

				for (auto next : followers[pos])
				{
					if (candy[next] < 1)
					{
						candy[next]++;
						user[next]++;
						q.push(next);
					}
				}
			}
			break;
		}
		case 'Q':
		{
			for (int i = 0; i < N; i++) user[i]++;
			break;
		}
		case 'K':
		{
			int sender = i % N;
			int giver = cards[++card_idx] - '0';
			followers[sender].push_back(giver);
			break;
		}
		}
	}
}

int main()
{
	init();
	solve();
	for (int i = 0; i < N - 1; i++) printf("%d ", user[i]);
	printf("%d", user[N-1]);
	return 0;
}