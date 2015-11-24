#include <bits/stdc++.h>
using namespace std;
const int sz = 10010;
int f[sz], a[sz];
typedef long long ll;
ll power(ll a, ll n, ll mod) {
	ll pow = a;
	ll result = 1;
	while (n) {
		if (n & 1)
			result = (result * pow) % mod;
		pow = (pow * pow) % mod;
		n >>= 1;
	}
	return result;
}
ll sumdigit(ll n) {
	ll res = 0;
	while (n) {
		res += n % 10;
		n /= 10;
	}
	return res;
}
bool witness(ll n, ll s, ll d, ll a) {
	ll x = power(a, d, n);
	ll y;
	while (s) {
		y = (x * x) % n;
		if (y == 1 && x != 1 && x != n - 1)
			return false;
		x = y;
		--s;
	}
	if (y != 1)
		return false;
	return true;
}

bool isPrime(ll n) {
	if (((!(n & 1)) && n != 2) || (n < 2) || (n % 3 == 0 && n != 3))
		return false;
	if (n <= 3)
		return true;
	ll d = n / 2;
	ll s = 1;
	while (!(d & 1)) {
		d /= 2;
		++s;
	}
	if (n < 1373653)
		return witness(n, s, d, 2) && witness(n, s, d, 3);
	if (n < 9080191)
		return witness(n, s, d, 31) && witness(n, s, d, 73);
	if (n < 4759123141LL)
		return witness(n, s, d, 2) && witness(n, s, d, 7)
				&& witness(n, s, d, 61);
	return true;
}

int main() {
	int n, t, i, j, k, check;
	scanf("%d", &t);
	while (t--) {
		scanf(" %d", &n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			f[i] = a[i];
			if (i > 0)
				f[i] += f[i - 1];
		}
		bool ans = 0;
		for (i = 1; i < n && !ans; ++i) {
			k = i;
			for (j = 0; k < n && !ans; ++j, ++k) {
				if (j == 0)
					check = f[k];
				else
					check = f[k] - f[j - 1];
				if (isPrime(check)) {
					ans = 1;
					break;
				}
			}
		}
		if (!ans) {
			printf("This sequence is anti-primed.\n");
		} else {
			printf("Shortest primed subsequence is length %d: ", k - j + 1);
			printf("%d", a[j]);
			for (i = j + 1; i <= k; ++i) {
				printf(" %d", a[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
