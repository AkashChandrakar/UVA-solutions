#include <bits/stdc++.h>
using namespace std;
map<string, bool> hash;
bool cut(string s) {
	if (s.empty())
		return true;
	bool f = false;
	int j;
	if (hash.count(s) != 0)
		return hash[s];
	int len = s.length();
	for (int i = 0; i < len && !f; ++i) {
		for (j = i; j < len && s[i] == s[j]; ++j)
			;
		if (j - i >= 2)
			f = f | cut(s.substr(0, i) + s.substr(j));
		i = j - 1;
	}
	hash[s] = f;
	return f;
}
int main() {
	string s;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		cin >> s;
		if (i != 0)
			cout << endl;
		cout << cut(s);
	}
	return 0;
}
