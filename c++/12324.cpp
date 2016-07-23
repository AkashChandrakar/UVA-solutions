#include <bits/stdc++.h>
using namespace std;
const int sz = 110;
typedef long long ll;
int cache[sz][sz * 10];
int dist[sz], timees[sz];
int n;
int f(int journey, int timeReamining) {
	if (journey == n) {
		return 0;
	}
	if (cache[journey][timeReamining] != -1)
		return cache[journey][timeReamining];
	int with = INT_MAX;
	if (timeReamining) {
		with = f(journey + 1, timeReamining + timees[journey] - 1)
				+ dist[journey] / 2;
	}
	int without = f(journey + 1, timeReamining + timees[journey])
			+ dist[journey];
	int mn = min(with, without);
	cache[journey][timeReamining] = mn;
	return mn;
}

int main() {
	//freopen("actual.txt", "w", stdout);
	int a, i, j, k;
	while (1) {
		scanf("%d", &n);
		fill(&cache[0][0], &cache[sz][0], -1);
		if (n == 0)
			break;
		for (i = 0; i < n; ++i) {
			scanf("%d %d", &dist[i], &timees[i]);
		}
		printf("%d\n",f(0, 0));
	}
	return 0;
}
