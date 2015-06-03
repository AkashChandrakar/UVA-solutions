#include <bits/stdc++.h>
using namespace std;

int main() {
	int cases, k;
	cin >> cases;
	map<char, float> hash;
	int cost, lines;
	char c;
	string line;
	double total_cost = 0.0;
	for (int i = 0; i < cases; ++i) {
		cin >> k;
		hash.clear();
		for (int j = 0; j < k; ++j) {
			cin >> c >> cost;
			hash[c] = cost / 100.0;
		}
		cin >> lines;
		cin.ignore();
		total_cost = 0.0;
		for (int j = 0; j < lines; ++j) {
			getline(cin, line);
			for (int t = 0; t < line.length(); ++t) {
				c = line[t];
				if (hash.count(c) != 0)
					total_cost += hash[c];
			}
		}
		printf("%.2f$\n",total_cost);
	}
	return 0;
}
