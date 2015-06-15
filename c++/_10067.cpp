/*
 * BFS
 * Sample Input
 2
 8 0 5 6
 6 5 0 8
 5
 8 0 5 7
 8 0 4 7
 5 5 0 8
 7 5 0 8
 6 4 0 8
 0 0 0 0
 5 3 1 7
 8
 0 0 0 1
 0 0 0 9
 0 0 1 0
 0 0 9 0
 0 1 0 0
 0 9 0 0
 1 0 0 0
 9 0 0 0
 Sample Output
 14
 -1
 */
#include <bits/stdc++.h>
using namespace std;
const int sz = 10001;
const int INF = INT_MAX / 2;
typedef pair<int, int> ii;
typedef pair<ii, ii> i4;
int da[] = { 1, -1, 0, 0, 0, 0, 0, 0 };
int db[] = { 0, 0, 1, -1, 0, 0, 0, 0, };
int dc[] = { 0, 0, 0, 0, 1, -1, 0, 0 };
int dd[] = { 0, 0, 0, 0, 0, 0, 1, -1 };
int dist[sz];
int label(i4 n) {
	return (n.first.first * 1000 + n.first.second * 100 + n.second.first * 10
			+ n.second.second);
}

int bfs(i4 &s, i4 &t) {
	int adj, node = label(s);
	dist[node] = 0;
	int a, b, c, d;
	queue<i4> q;
	i4 n, m;
	q.push(s);
	while (!q.empty()) {
		n = q.front();
		node = label(n);
		a = n.first.first;
		b = n.first.second;
		c = n.second.first;
		d = n.second.second;
		q.pop();
		for (int i = 0; i < 8; ++i) {
			m = i4(ii((a + da[i] + 10) % 10, (b + db[i] + 10) % 10),
					ii((c + dc[i] + 10) % 10, (d + dd[i] + 10) % 10));
			adj = label(m);
			//cout << node << " " << adj << endl;
			if (adj >= 0 && adj <= 9999 && dist[adj] == INF) {
				dist[adj] = dist[node] + 1;
				q.push(m);
			}
		}
		//getchar();
	}
	node = label(t);
	if (dist[node] == INF)
		return -1;
	else
		return dist[node];
}
int main() {
	int n, t;
	scanf("%d", &t);
	i4 source, target, exclude;
	int a, b, c, d;
	for (int var = 0; var < t; ++var) {
		fill(dist, dist + sz, INF);
		scanf("%d %d %d %d", &a, &b, &c, &d);
		source = i4(ii(a, b), ii(c, d));
		scanf("%d %d %d %d", &a, &b, &c, &d);
		target = i4(ii(a, b), ii(c, d));
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d %d %d", &a, &b, &c, &d);
			exclude = i4(ii(a, b), ii(c, d));
			int l = label(exclude);
			dist[l] = 0;
		}
		printf("%d\n", bfs(source, target));
	}
	return 0;
}
