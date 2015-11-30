#include <bits/stdc++.h>
using namespace std;
vector<string> v;
map<string, int> hash;
set<string> S;
int main() {
	string s;
	while (cin >> s && s != "#") {
		v.push_back(s);
		for (int i = 0; i < s.length(); ++i) {
			s[i] = tolower(s[i]);
		}
		sort(s.begin(), s.end());

		if (hash.find(s) == hash.end()) {
			hash[s] = 1;
		} else {
			++hash[s];
		}
	}
	for (int i = 0; i < v.size(); ++i) {
		s = v[i];
		string r = s;
		for (int i = 0; i < s.length(); ++i) {
			s[i] = tolower(s[i]);
		}
		sort(s.begin(), s.end());
		if (hash[s] == 1) {
			S.insert(r);
		}
	}
	for (set<string>::iterator it = S.begin(); it != S.end(); ++it) {
		cout << *it << endl;
	}
	return 0;
}
