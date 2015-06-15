/*
 * Sample Input
 7 10
 1 2 30
 1 3 15
 1 4 10
 2 4 25
 2 5 60
 3 4 40
 3 6 20
 4 7 35
 5 7 20
 6 7 30
 1 7 99
 7 10
 1 2 30
 1 3 15
 1 4 10
 2 4 25
 2 5 60
 3 4 40
 3 6 20
 4 7 35
 5 7 20
 6 7 30
 1 7 99
 0 0
 Sample Output
 Scenario #1
 Minimum Number of Trips = 5
 */
#include <bits/stdc++.h>
using namespace std;
const int sz = 102;
const int INF = INT_MAX / 2;
int cache[sz][sz];
void floydwarshall(int n) {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cache[i][j] = max(cache[i][j], min(cache[i][k], cache[k][j]));
			}
		}
	}
}
int main() {
	int n, r, a, b, c, dist, trips, t = 1;
	while (scanf("%d %d", &n, &r) && n && r) {
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				cache[i][j] = 0;
		for (int var = 0; var < r; ++var) {
			scanf("%d %d %d", &a, &b, &c);
			cache[a][b] = c;
			cache[b][a] = c;
		}
		scanf("%d %d %d", &a, &b, &c);
		floydwarshall(n);
		dist = cache[a][b] - 1;
		trips = ceil((c * 1.00) / dist);
		printf("Scenario #%d\n", t++);
		printf("Minimum Number of Trips = %d\n\n", trips);
	}
	return 0;
}
