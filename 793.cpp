#include <bits/stdc++.h>
using namespace std;
const int sz = 10000;
int parent[sz];
int size[sz];
int maxConnected = 0;
void init() {
	for (int i = 0; i < sz; ++i) {
		parent[i] = i;
		size[i] = 1;
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
	size[q] += size[p];
}
bool Find(int a, int b) {
	return root(a) == root(b);
}

int main() {
	string line;
	int cases;
	int x, y, right, wrong;
	right = wrong = 0;
	char q;
	scanf("%d", &cases);
	init();
	for (int t = 0; t < cases; ++t) {
		scanf("%c %d %d", &q, &x, &y);
		x = line[0] - 'A';
		y = line[1] - 'A';
		if (q == 'c') {
			Union(x, y);
		} else {
			if (Find(x, y))
				++right;
			else
				++wrong;
		}
	}
	printf("%d,%d\n", right, wrong);
	return 0;
}
