#include <bits/stdc++.h>
using namespace std;
int main() {
	int cases, size;
	cin >> cases;
	map<string, int> hash;
	string line;
	map<string, int>::iterator i;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, line);
	for (int t = 0; t < cases; ++t) {
		hash.clear();
		size = 0;
		while (getline(cin, line) && !line.empty()) {
			if (hash.count(line) == 0) {
				hash[line] = 1;
			} else {
				hash[line]++;
			}
			++size;
		}
		for (i = hash.begin(); i != hash.end(); ++i) {
			cout << i->first;
			printf(" %.4lf\n", (100.0 * i->second) / size);
		}
		if (t != cases - 1)
			cout << endl;
	}
	return 0;
}
