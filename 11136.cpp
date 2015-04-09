#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, k;
	int bill, value;
	long long cost;
	map<int, int> hash;
	map<int, int>::iterator it1;
	map<int, int>::reverse_iterator it2;
	while (1) {
		cin >> t;
		if (t == 0)
			break;
		cost = 0L;
		hash.clear();
		while (t--) {
			cin >> k;
			for (int var = 0; var < k; ++var) {
				cin >> bill;
				if (hash.count(bill) == 0) {
					hash[bill] = 1;
				} else {
					value = hash[bill];
					hash[bill] = ++value;
				}
			}
			it1 = hash.begin();
			it2 = hash.rbegin();

			cost += it2->first - it1->first;
			if (hash[it2->first] == 1)
				hash.erase(it2->first);
			else {
				value = hash[it2->first];
				hash[it2->first] = --value;
			}
			if (hash[it1->first] == 1)
				hash.erase(it1->first);
			else {
				value = hash[it1->first];
				hash[it1->first] = --value;
			}

		}
		cout << cost << endl;
	}
	return 0;
}
