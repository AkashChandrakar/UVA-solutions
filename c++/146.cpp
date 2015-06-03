#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	string res;
	while (true) {
		cin >> s;
		if (s == "#")
			break;
		res = s;
		next_permutation(s.begin(), s.end());
		sort(res.begin(), res.end());
		if (s == res)
			cout << "No Successor" << endl;
		else
			cout << s << endl;
	}
	return 0;
}
