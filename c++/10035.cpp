/*
 * Sample Input

 123 456
 555 555
 123 594
 0 0
 Output for Sample Input

 No carry operation.
 3 carry operations.
 1 carry operation.

 */
#include <bits/stdc++.h>
using namespace std;
void equalize(string &s1, string &s2) {
	int len = s1.length();
	int dif = len - s2.length();
	for (int i = 0; i < dif; ++i) {
		s2 = "0" + s2;
	}
}
int carryop(string s1, string s2) {
	if (s1.length() > s2.length()) {
		equalize(s1, s2);
	} else {
		equalize(s2, s1);
	}
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	int cnt = 0, a, b, c = 0;
	for (int i = 0; i < (int) s1.length(); ++i) {
		a = s1[i] - '0', b = s2[i] - '0';
		if (a + b + c >= 10) {
			c = 1;
			++cnt;
		} else {
			c = 0;
		}
	}
	return cnt;
}
int main() {
	int n;
	string s1, s2;
	while (cin >> s1 >> s2) {
		if (s1 == "0" && s2 == "0") {
			break;
		}
		n = carryop(s1, s2);
		if (n == 0) {
			cout << "No carry operation.\n";
		} else if (n == 1) {
			cout << "1 carry operation.\n";
		} else {
			cout << n << " carry operations.\n";
		}
	}

	return 0;
}
