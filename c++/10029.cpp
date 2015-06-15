#include <bits/stdc++.h>
using namespace std;
map<string, int> hash;
int main() {
	string s1, s2;
	int res, len;
	res = 0;
	while (cin >> s1) {
		len = 1;
		//insertion
		for (int i = 0; i <= s1.length(); ++i) {
			for (char ch = 'a'; ch <= 'z'; ++ch) {
				s2 = s1;
				s2.insert(i, 1, ch);
				if (s2 > s1)
					break;
				if (hash.count(s2) != 0) {
					len = max(len, hash[s2] + 1);
				}
			}
		}
		//deletion
		for (int i = 0; i < s1.length(); ++i) {
			s2 = s1;
			s2.erase(i, 1);
			if (hash.count(s2) != 0) {
				len = max(len, hash[s2] + 1);
			}
		}
		//replacement
		for (int i = 0; i < s1.length(); ++i) {
			for (int ch = 'a'; ch <= 'z' && ch != s1[i]; ++ch) {
				s2 = s1;
				s2[i] = ch;
				if (s2 > s1)
					break;
				if (hash.count(s2) != 0) {
					len = max(len, hash[s2] + 1);
				}
			}
		}
		hash[s1] = len;
		res = max(res, len);
	}
	cout << res << endl;
	return 0;
}
