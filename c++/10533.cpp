#include <bits/stdc++.h>
using namespace std;
const int sz = 1000010;
bool prime[sz];
int digprime[sz];
set<int> primes;

bool isdigitprime(int n) {
	if (!prime[n])
		return 0;
	int rem = 0;
	while (n) {
		rem += (n % 10);
		n /= 10;
	}
	return primes.find(rem) != primes.end();
}

void sieve() {
	fill(prime, prime + sz, 1);
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i < sz; ++i) {
		if (prime[i]) {
			for (int j = i * i; j < sz; j += i)
				prime[j] = 0;
		}
	}
	for (int i = 2; i < sz; ++i)
		if (prime[i])
			primes.insert(i);
	for (int i = 2; i < sz; ++i) {
		digprime[i] = digprime[i - 1];
		if (isdigitprime(i))
			++digprime[i];
	}
}

int main() {
	int a, b, t;
	sieve();
	scanf("%d", &t);
	while (t--) {
		scanf(" %d %d", &a, &b);
		int ans = digprime[b] - digprime[a - 1];
		printf("%d\n", ans);
	}
	return 0;
}
