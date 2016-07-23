#include <bits/stdc++.h>
using namespace std;
const int sz = 1 << 10;
typedef long long ll;
int mask = (1 << 9) - 1;
map<int, int> cache;
map<int, int>::iterator it;
int f() {
	int rs = -1;
	int x, y, z;

	for (it = cache.begin(); it != cache.end(); ++it) {
		x = it->first;
		vector<int> v;
		for (int i = 0; i < 9; ++i) {
			if ((x & (1 << i)) == 0) {
				v.push_back(i);
			}
		}
		for (int i = 0; i < 6; ++i) {
			for (int j = i + 1; j < 6; ++j) {
				for (int k = j + 1; k < 6; ++k) {
					y = 0;
					y = (1 << v[i]) | (1 << v[j]) | (1 << v[k]);
					if (cache.find(y) != cache.end()) {
						z = ~(x | y);
						z &= mask;
						if (cache.find(z) != cache.end()) {
							rs = max(rs, cache[x] + cache[y] + cache[z]);
						}
					}
				}
			}
		}
	}
	return rs;
}

int main() {
	int cnt = 1;
	//freopen("actual.txt", "w", stdout);
	int a, i, j, k;
	int key = 0, value;
	while (1) {
		scanf("%d", &a);
		if (a == 0)
			break;
		cache.clear();
		for (int t = 0; t < a; ++t) {
			cin >> i >> j >> k;
			--i, --j, --k;
			key = 0;
			key = (1 << i) | (1 << j) | (1 << k);
			scanf("%d", &value);
			if (cache.find(key) == cache.end())
				cache[key] = value;
			else if (cache[key] < value)
				cache[key] = value;

		}
		printf("Case %d: %d\n", cnt, f());
		++cnt;
	}
	return 0;
}
