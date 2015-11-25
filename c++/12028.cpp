#include <bits/stdc++.h>
using namespace std;
const int sz = 100010;
const int mod = 1000007;
long long a[sz];

int main() {
	int t, n, k, c, minus, plus;
	scanf("%d", &t);

	for (int i = 1; i <= t; ++i) {
		scanf("%d %d %d %d", &k, &c, &n, &a[0]);
		for (int j = 1; j < n; ++j) {
			a[j] = (a[j - 1] * k + c) % mod;
		}
		sort(a, a + n);
		minus = n - 1;
		plus = 0;
		long long sum = 0;
		for (int k = 0; k < n; ++k, --minus, ++plus) {
			sum = sum + ((plus - minus) * a[k]);
		}
		printf("Case %d: %lld\n", i, sum);
	}

	return 0;
}
