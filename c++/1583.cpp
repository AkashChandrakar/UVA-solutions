#include <bits/stdc++.h>
using namespace std;
const int sz = 1000010;
int f[sz];
int sdigits(int n) {
	int res = 0;
	while (n) {
		res += (n % 10);
		n /= 10;
	}
	return res;
}

void fill() {
	for (int i = 1; i < sz; ++i) {
		int mark = sdigits(i) + i;
		if (mark < sz && f[mark] == 0) {
			f[mark] = i;
		}
	}
}

int main() {
	int t, n;
	fill();
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", f[n]);
	}
	return 0;
}
