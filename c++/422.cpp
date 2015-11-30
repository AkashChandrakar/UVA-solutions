#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
vector<int> v;
map<char, ii> hash;
char s[500];

ll process() {
	int len = strlen(s);
	ll res = 0;
	char chr = 'a';
	ii a, b, c;
	stack<char> S;
	map<char, ii> temphash;
	for (int i = 0; i < len; ++i) {
		if (s[i] == '(')
			S.push('(');
		else if (s[i] == ')') {
			if (hash.find(S.top()) != hash.end())
				b = hash[S.top()];
			else
				b = temphash[S.top()];
			S.pop();
			if (hash.find(S.top()) != hash.end())
				a = hash[S.top()];
			else
				a = temphash[S.top()];
			S.pop();
			if (a.second != b.first)
				return -1;
			c.first = a.first, c.second = b.second;
			res += (a.first * a.second * b.second);
			S.pop();
			temphash[chr] = c;
			S.push(chr);
			++chr;
		} else {
			S.push(s[i]);
		}
	}
	return res;
}
int main() {
	int n, row, col;
	ll res;
	char c;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("\n%c %d %d", &c, &row, &col);
		hash[c] = ii(row, col);
	}
	while (scanf("%s", s) != EOF) {
		res = process();
		if (res == -1)
			printf("error\n");
		else
			printf("%lld\n", res);
	}
	return 0;
}
