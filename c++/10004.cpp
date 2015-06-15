/*
 * Graph Bipartatite check
 * Sample Input
 3
 3
 0 1
 1 2
 2 0
 3
 2
 0 1
 1 2
 9
 8
 0 1
 0 2
 0 3
 0 4
 0 5
 0 6
 0 7
 0 8
 0
 Sample Output
 NOT BICOLORABLE.
 BICOLORABLE.
 BICOLORABLE.
 */
#include <bits/stdc++.h>
using namespace std;
const int sz = 202;
vector<int> adj[sz];
int dist[sz];
const int INF = INT_MAX / 2;
bool isbipartiate() {
	dist[0] = 0;
	bool f = true;
	queue<int> q;
	q.push(0);
	int u, v;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int i = 0; i < adj[u].size(); ++i) {
			v = adj[u][i];
			if (dist[v] == INF) {
				dist[v] = 1 - dist[u];
				q.push(v);
			} else if (dist[u] == dist[v])
				return false;
		}
	}
	return f;
}
int main() {
	int n, m, i, j;
	while (scanf("%d", &n) && n) {
		scanf("%d", &m);
		for (int p = 0; p < n; ++p) {
			adj[p].clear();
			dist[p] = INF;
		}
		for (int var = 0; var < m; ++var) {
			scanf("%d %d", &i, &j);
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
		if (isbipartiate()) {
			printf("BICOLORABLE.\n");
		} else {
			printf("NOT BICOLORABLE.\n");
		}
	}
	return 0;
}
