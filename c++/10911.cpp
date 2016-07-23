#include <bits/stdc++.h>
using namespace std;
const int sz = 1 << 16;
typedef long long ll;
double cache[sz];
int x[sz], y[sz];
char s[30];
int power;
int n;

double dist(int x1, int y1, int x2, int y2) {
	double p, q;
	p = (x2 - x1);
	q = (y2 - y1);
	return sqrt(p * p + q * q);
}

double f(int mask) {
	if (mask == (power - 1))
		return 0.0;
	if (cache[mask] != -1)
		return cache[mask];
	double mn = INT_MAX;
	for (int i = 0; i < 2 * n; ++i) {
		if (((1 << i) & mask) == 0) {
			for (int j = i + 1; j < 2 * n; ++j) {
				if (((1 << j) & mask) == 0) {
					double tmp = f(mask | (1 << i) | (1 << j))
							+ dist(x[i], y[i], x[j], y[j]);
					mn = min(mn, tmp);
				}
			}
		}
	}
	cache[mask] = mn;
	return mn;
}

int main() {
	int cnt = 1;
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		power = 1 << (2 * n);
		for (int i = 0; i < 2 * n; ++i) {
			scanf("%s %d %d", s, &x[i], &y[i]);
		}
		fill(cache, cache + power, -1);
		printf("Case %d: %.2lf\n", cnt, f(0));
		++cnt;
	}
	return 0;
}
