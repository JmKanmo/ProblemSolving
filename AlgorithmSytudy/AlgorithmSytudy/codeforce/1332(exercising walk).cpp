#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	ll t; cin >> t;
	while (t--) {
		ll a, b, c, d, x, y, x1, y1, x2, y2;
		cin >> a >> b >> c >> d;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		ll xt = x - a + b;
		ll yt = y - c + d;
		if (x1 <= xt && xt <= x2 && y1 <= yt && yt <= y2 && (x1 < x2 || (!a && !b)) && (y2 > y1 || (!c && !d)))
			cout << "YES";
		else cout << "NO";
		cout << "\n";
	}
	return 0;
}