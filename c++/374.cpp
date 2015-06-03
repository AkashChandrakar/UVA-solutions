#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll repsq(ll a, ll b, ll c) {
	if (b == 0)
		return 1;
	ll sq = repsq(a, b / 2, c);
	sq = (sq * sq) % c;
	if (b & 1)
		sq = (sq * a) % c;
	return sq % c;
}

int main() {
	ll a, b, c;
	string s;
	while (cin >> a >> b >> c) {
		cout << repsq(a, b, c) << endl;
	}
	return 0;
}

