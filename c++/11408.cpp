#include <bits/stdc++.h>
using namespace std;
const int sz = 5000010;
bool prime[sz];
int f[sz];
int sumfactors[sz];
void sieve() {
	fill(prime, prime + sz, 1);
	prime[0] = prime[1] = 0;
	for (int i = 2; i < sz; ++i) {
		if (prime[i]) {
			sumfactors[i] += i;
			for (int j = 2 * i; j < sz; j += i) {
				sumfactors[j] += i;
				prime[j] = 0;
			}
		}
	}
	for (int i = 2; i < sz; ++i) {
		f[i] = f[i - 1];
		if (prime[sumfactors[i]])
			++f[i];
	}
}

int main() {
	int a, b;
	sieve();
	while (1) {
		scanf("%d", &a);
		if (a == 0)
			break;
		scanf("%d", &b);
		printf("%d\n", f[b] - f[a - 1]);
	}
	return 0;
}
