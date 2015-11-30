#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
vector<int> v;
set<string> hash;

vector<string> process(string s) {
	int i = 0, len;
	vector<string> v;
	len = s.length();
	while (i < len) {
		while (i < len && !isalpha(s[i]))
			++i;
		string res = "";
		while (i < len && isalpha(s[i])) {
			res += tolower(s[i]);
			++i;
		}
		if (res.length() > 0)
			v.push_back(res);
	}
	return v;
}

int main() {
	string s, low;
	while (getline(cin, s)) {
		vector<string> v = process(s);
		for (int i = 0; i < v.size(); ++i) {
			hash.insert(v[i]);
		}
	}
	for (set<string>::iterator it = hash.begin(); it != hash.end(); ++it) {
		cout << *it << endl;
	}
	return 0;
}
