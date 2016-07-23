#include <bits/stdc++.h>
using namespace std;
const int sz = 1 << 12;
typedef long long ll;
int cache[sz];
int twelve = 12;
int INF = 1000;
int cnt(int n) {
	int res = 0;
	while (n) {
		n &= (n - 1);
		++res;
	}
	return res;
}

void p(int n) {
	for (int i = 0; i < twelve; ++i) {
		if (n & 1)
			cout << "o";
		else
			cout << "-";
	}
	cout << endl;
}

int f(int mask) {
	int tmp, res;
	if (cache[mask] != INF)
		return cache[mask];
	res = cnt(mask);
	int i, j, k;
	int tmask;
	for (i = 1; i < twelve; ++i) {
		j = i - 1;
		if ((((1 << i) & mask) != 0) && (((1 << j) & mask) != 0)) {
			if (j - 1 >= 0) {
				k = j - 1;
				if (((1 << k) & mask) == 0) {
					tmask = mask;
					tmask |= (1 << k);
					tmask &= ~(1 << j);
					tmask &= ~(1 << i);
					tmp = f(tmask);
					res = min(tmp, res);
				}
			}
			if (i + 1 < twelve) {
				k = i + 1;
				if (((1 << k) & mask) == 0) {
					tmask = mask;
					tmask |= (1 << k);
					tmask &= ~(1 << j);
					tmask &= ~(1 << i);
					tmp = f(tmask);
					res = min(tmp, res);
				}
			}
		}
	}
	cache[mask] = res;
	return res;
}
int main() {

	//freopen("actual.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	string need;
	char ch;
	int a, i, n, j, k, orders;
	scanf("%d", &n);
	int mask;
	while (n--) {
		fill(cache, cache + sz, INF);
		mask = 0;
		for (int i = 0; i < 12; ++i) {
			scanf(" %c", &ch);
			if (ch == 'o') {
				mask |= (1 << i);
			}
		}
		printf("%d\n", f(mask));
	}
	return 0;
}
