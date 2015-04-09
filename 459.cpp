#include <bits/stdc++.h>
using namespace std;
const int sz = 27;
int parent[sz];
int maxConnected = 0;
void init() {
	for (int i = 0; i < sz; ++i) {
		parent[i] = i;
	}
}
int root(int idx) {
	while (idx != parent[idx]) {
		//path compression
		parent[idx] = parent[parent[idx]];
		idx = parent[idx];
	}
	return idx;
}
void Union(int a, int b) {
	int p = root(a);
	int q = root(b);
	if (p == q) //both are already connected
		return;
	parent[p] = q;
	--maxConnected;
}
bool Find(int a, int b) {
	return root(a) == root(b);
}

int main() {
	string line;
	int cases;
	cin >> cases;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, line);
	int x, y;
	for (int t = 0; t < cases; ++t) {
		init();
		getline(cin, line);
		maxConnected = line[0] - 'A' + 1;
		while (getline(cin, line) && !line.empty()) {
			x = line[0] - 'A';
			y = line[1] - 'A';
			Union(x, y);
		}
		cout << maxConnected << endl;
		if (t != cases - 1)
			cout << endl;
	}
	return 0;
}
