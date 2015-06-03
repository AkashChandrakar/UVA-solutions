#include <bits/stdc++.h>
using namespace std;
const int sz = 100000;
int parent[sz];
int size[sz];
int maxConnected = 0;
void init(int n) {
	for (int i = 0; i < n; ++i) {
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
	maxConnected = max(maxConnected, size[q]);
}
bool Find(int a, int b) {
	return root(a) == root(b);
}

int main() {
	string line;
	int cases;
	int x, y, n, m;
	scanf("%d", &cases);
	for (int t = 0; t < cases; ++t) {
		scanf("%d %d", &n, &m);
		init(n);
		maxConnected = 0;
		for (int i = 0; i < m; ++i) {
			scanf("%d %d", &x, &y);
			x = line[0] - 'A';
			y = line[1] - 'A';
			Union(x, y);
		}
		printf("%d", maxConnected);
		if (t != cases - 1)
			printf("\n");
	}
	return 0;
}
