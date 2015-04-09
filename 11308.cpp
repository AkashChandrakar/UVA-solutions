#include <bits/stdc++.h>
using namespace std;
bool comp(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}
int main() {
	int cases;
	cin >> cases;
	string binder, recepie;
	vector<pair<string, int> > recepies;
	map<string, int> cost;
	int budget;
	string indg;
	int i, c, k, no_of_recepies, tot;
	for (int t = 0; t < cases; ++t) {
		getline(cin, binder);
		transform(binder.begin(), binder.end(), binder.begin(), ::toupper);
		cout << binder << endl;
		recepies.clear();
		cost.clear();
		cin >> i >> no_of_recepies >> budget;
		for (int var = 0; var < i; ++var) {
			cin >> indg >> c;
			cost[indg] = c;
		}
		for (int var = 0; var < no_of_recepies; ++var) {
			getline(cin, recepie);
			cin >> k;
			tot = 0;
			for (int var1 = 0; var1 < k; ++var1) {
				cin >> indg >> c;
				tot += (c * cost[indg]);
			}
			if (tot <= budget)
				recepies.push_back(make_pair(recepie, tot));
		}
		if (recepies.size() == 0) {
			cout << "Too expensive!" << endl;
		} else {
			for (int var = 0; var < recepies.size(); ++var) {
				cout << recepies[var].first << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
