#include <bits/stdc++.h>
using namespace std;
const int sz = 1000010;
typedef long long ll;
ll hprimes[sz];
bool isprime[sz];
ll hsemirimes[sz];
int main() {

	int i, j, n, len;
	fill(isprime, isprime + sz, 1);
	j = 0;
	for (int i = 5; i <= 1000; i += 4) {
		if (isprime[i]) {
			hprimes[j++] = i;
			for (int j = i * i; j < sz; j += i)
				isprime[j] = false;
		}
	}
	for (int i = 1001; i < sz; i += 4) {
		if (isprime[i])
			hprimes[j++] = i;
	}
	len = j;
	for (i = 0; i < len / 5; ++i) {
		for (j = i; j < len && hprimes[i] * hprimes[j] < sz; ++j) {
			hsemirimes[hprimes[i] * hprimes[j]] = 1;
		}
	}
	for (i = 1; i < sz; ++i) {
		hsemirimes[i] += hsemirimes[i - 1];
	}
	while (scanf("%d", &n) && n) {
		printf("%d %lld\n", n, hsemirimes[n]);
	}
	return 0;
}
