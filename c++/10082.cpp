#include <bits/stdc++.h>
using namespace std;

int main() {
	string s = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
	map<char, char> hash;
	for (int i = 1; i < s.length(); ++i) {
		hash[s[i]] = s[i - 1];
	}
	string line;
	while (getline(cin, line)) {
		for (int i = 0; i < line.length(); ++i) {
			if (line[i] != ' ')
				line[i] = hash[line[i]];
		}
		cout << line << endl;
	}
	return 0;
}
