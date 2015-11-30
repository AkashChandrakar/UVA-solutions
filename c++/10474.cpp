#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 10010;
int hash[sz], arr[sz];

int main() {
	int n, q, cs = 0, idx;
	while (scanf("%d %d", &n, &q) && n) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		sort(arr, arr + n);
		fill(hash, hash + sz, 0);
		for (int i = 0; i < n; ++i) {
			if (hash[arr[i]] == 0) {
				hash[arr[i]] = i + 1;
			}
		}
		printf("CASE# %d:\n", ++cs);
		for (int i = 0; i < q; ++i) {
			scanf("%d", &idx);
			if (hash[idx] != 0) {
				printf("%d found at %d\n", idx, hash[idx]);
			} else {
				printf("%d not found\n", idx);
			}
		}
	}

	return 0;
}
