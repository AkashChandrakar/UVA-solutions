#include <bits/stdc++.h>
using namespace std;
const int sz = 1 << 15;
typedef long long ll;
int cache[sz];
int x[50];
int power;
int n;

int f(int mask) {
	if (mask == (power - 1))
		return 0;
	if (cache[mask] != -1)
		return cache[mask];
	int tmp, mx = 0;
	for (int i = 0; i < n; ++i) {
		if (((1 << i) & mask) == 0) {
			for (int j = i + 1; j < n; ++j) {
				if (((1 << j) & mask) == 0) {
					for (int k = j + 1; k < n; ++k) {
						if (((1 << k) & mask) == 0
								&& (x[i] + x[j] + x[k] >= 20)) {
							tmp = f(mask | (1 << i) | (1 << j) | (1 << k)) + 1;
							mx = max(mx, tmp);
						}
					}
				}
			}
		}
	}
	cache[mask] = mx;
	return mx;
}

int main() {
	int cnt = 1;
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		power = 1 << n;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &x[i]);
		}
		fill(cache, cache + power, -1);
		printf("Case %d: %d\n", cnt, f(0));
		++cnt;
	}
	return 0;
}
