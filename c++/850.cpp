#include <bits/stdc++.h>
using namespace std;
const string plaintext = "the quick brown fox jumps over the lazy dog";
map<char, char> hash;
char key;
bool ismappable(string encrypted[], int n) {
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cnt = 0;
		if (encrypted[i].length() == plaintext.length()) {
			for (int j = 0; j < plaintext.length(); ++j) {
				if ((plaintext[j] == ' ' && encrypted[i][j] != ' ')
						|| (plaintext[j] != ' ' && encrypted[i][j] == ' ')) {
					hash.clear();
					break;
				}
				key = encrypted[i][j];
				if (hash.count(key) == 0) {
					++cnt;
					hash[key] = plaintext[j];
				} else {
					if (hash[key] != plaintext[j]) {
						hash.clear();
						break;
					} else {
						++cnt;
					}
				}
			}
			if (cnt == plaintext.length())
				return true;
		}
	}
	hash.clear();
	return false;
}
int main() {
	int cases;
	cin >> cases;
	string line;
	int i, n, m, q;
	char key;
	getline(cin, line);
	for (int t = 0; t < cases; ++t) {
		//read blank line
		string encrypted[101];
		i = 0;
		while (getline(cin, encrypted[i])) {
			if (encrypted[i].empty()) {
				break;
			}
			++i;
		}
		if (ismappable(encrypted, i)) {
			for (int j = 0; j < i; ++j) {
				for (int k = 0; k < encrypted[i].length(); ++k) {
					key = encrypted[j][k];
					if (key == ' ')
						cout << " ";
					else
						cout << key;
				}
				cout << endl;
			}
			map<char, char>::iterator it;
			for (it = hash.begin(); it != hash.end(); ++it) {
				//cout << it->first << " " << it->second << endl;
			}
		} else {
			cout << "No solution." << endl;
		}
		cout << endl;
	}
	return 0;
}
