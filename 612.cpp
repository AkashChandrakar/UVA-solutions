#include <bits/stdc++.h>
using namespace std;

int countInversion(int n, string seq) {
	int res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (seq[i] > seq[j])
				++res;
		}
	}
	return res;
}
map<string, int> hash;
bool comp(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second) {
		return hash[a.first] < hash[b.first];
	} else {
		return a.second < b.second;
	}
}
int main() {
	string sequence;
	vector<pair<string, int> > DNA;
	int n, m;
	int invs;
	cin >> n >> m;
	for (int j = 0; j < m; ++j) {
		cin >> sequence;
		invs = countInversion(n, sequence);
		hash[sequence] = j;
		DNA.push_back(make_pair(sequence, invs));
	}
	stable_sort(DNA.begin(), DNA.end(), comp);
	vector<pair<string, int> >::iterator it;
	for (it = DNA.begin(); it != DNA.end(); ++it) {
		cout << it->first << endl;
	}
	return 0;
}

