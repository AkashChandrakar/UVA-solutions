#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
vector<ll> v;
set<ll> s;
int main() {
	ll n;
	priority_queue<ll, vector<ll>, greater<ll> > Q;
	Q.push(1);
	int cnt = 1500;
	while (cnt != 1) {
		n = Q.top();
		s.insert(n);
		Q.pop();
		if (s.find(n * 2) == s.end()) {
			s.insert(n * 2);
			Q.push(n * 2);
		}
		if (s.find(n * 3) == s.end()) {
			s.insert(n * 3);
			Q.push(n * 3);
		}
		if (s.find(n * 5) == s.end()) {
			s.insert(n * 5);
			Q.push(n * 5);
		}
		--cnt;
	}
	printf("The 1500'th ugly number is %lld.\n", Q.top());
	return 0;
}
