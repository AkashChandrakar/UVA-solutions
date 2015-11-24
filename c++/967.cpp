#include <bits/stdc++.h>
using namespace std;
const int sz = 1000010;
bool prime[sz];
int circularprime[sz];
set<int> primes;

int nofoDigits(int n) {
	int res = 0;
	while (n) {
		n /= 10;
		++res;
	}
	return res;
}

bool iscirprime(int n) {
	if (!prime[n])
		return 0;
	int len = nofoDigits(n);
	if (len == 1)
		return 1;
	int rem;
	--len;
	for (int i = 0; i < len; ++i) {
		rem = n % 10;
		n /= 10;
		n = rem * pow(10, len) + n;
		if (primes.find(n) == primes.end())
			return 0;
	}
	return 1;
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
		circularprime[i] = circularprime[i - 1];
		if (iscirprime(i))
			++circularprime[i];
	}
}

int main() {
	int a, b;
	sieve();
	while (1) {
		scanf("%d", &a);
		if (a == -1)
			break;
		scanf("%d", &b);
		int ans = circularprime[b] - circularprime[a - 1];
		if (ans == 0) {
			printf("No Circular Primes.");
		} else if (ans == 1) {
			printf("1 Circular Prime.");
		} else {
			printf("%d Circular Primes.", ans);
		}
		printf("\n");
	}
	return 0;
}
