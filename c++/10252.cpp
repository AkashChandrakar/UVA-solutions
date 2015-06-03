#include <bits/stdc++.h>
using namespace std;
int main() {
	string a, b;
	int times, idx, counta[26], countb[26];
	while (getline(cin, a)) {
		getline(cin, b);
		memset(counta, 0, sizeof(counta));
		memset(countb, 0, sizeof(countb));
		for (int i = 0; i < a.length(); ++i) {
			idx = a[i] - 'a';
			counta[idx]++;
		}
		for (int i = 0; i < b.length(); ++i) {
			idx = b[i] - 'a';
			countb[idx]++;
		}
		for (int i = 0; i < 26; ++i) {
			times = min(counta[i], countb[i]);
			for (int j = 0; j < times; ++j) {
				cout << (char) ('a' + i);
			}
		}
		cout << endl;
	}
	return 0;
}
